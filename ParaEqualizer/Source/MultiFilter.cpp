/*
 ==============================================================================
 
 MultiFilter.cpp
 Created: 11 Feb 2018 5:14:23pm
 Author:  Andrew Cloud
 
 ==============================================================================
 */

#include "MultiFilter.h"

MultiFilter::MultiFilter(FilterType type, float sampleRate, float defaultFreq) {
    updateSampleRate(sampleRate);
    fType = type;
    frequency = defaultFreq;
    dbGain = 0.f;
    q = 0.71f;
    filter = *new stk::BiQuad();
    updateCoefficients();
}

MultiFilter::~MultiFilter(){}

void MultiFilter::updateCoefficients() {
    switch (fType) {
        case FilterType::LowShelf:
            // Low Shelf Filter
            // Frequency occurs left of slope
            // Isn't balanced when attenuating...
            A = powf(10.f, dbGain/40.f);
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            b0 =      A * ( (A+1.f) - (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha );
            b1 =  2.f*A * ( (A-1.f) - (A+1.f)*cos_w0                      );
            b2 =      A * ( (A+1.f) - (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha );
            
            a0 =            (A+1.f) + (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha;
            a1 =  -2.f  * ( (A-1.f) + (A+1.f)*cos_w0                      );
            a2 =            (A+1.f) + (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha;
            
            b0 /= a0;
            b1 /= a0;
            b2 /= a0;
            a1 /= a0;
            a2 /= a0;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
        
        case FilterType::HighShelf:
            // High Shelf Filter
            // Frequency occurs left of slope
            // Isn't balanced when amplifying...
            A = powf(10.f, dbGain/40.f);
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            b0 =      A * ( (A+1.f) + (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha );
            b1 = -2.f*A * ( (A-1.f) + (A+1.f)*cos_w0                      );
            b2 =      A * ( (A+1.f) + (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha );
            
            a0 =            (A+1.f) - (A-1.f)*cos_w0 + 2.f*sqrtf(A)*alpha;
            a1 =    2.f * ( (A-1.f) - (A+1.f)*cos_w0                      );
            a2 =            (A+1.f) - (A-1.f)*cos_w0 - 2.f*sqrtf(A)*alpha;
            
            b0 /= a0;
            b1 /= a0;
            b2 /= a0;
            a1 /= a0;
            a2 /= a0;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
        
        case FilterType::Peak:
            // Zolzer's Implementation
            // Center frequency still skewed!
            w0 = 2.f * M_PI * frequency / fs;
            K = tanf(w0/2.f);
            if (dbGain >= 0) {
                V = powf(10.f, dbGain/20);
                D = 1.f + K/q + K*K;
                
                b0 = 1.f + V*K/q + K*K;
                b1 = 2.f * (K*K - 1.f);
                b2 = 1.f - V*K/q + K*K;
                a1 = b1;
                a2 = 1.f - K/q + K*K;
            }
            else {
                V = powf(10.f, -dbGain/20);
                D = 1.f + V*K/q + K*K;
                
                b0 = 1.f + K/q + K*K;
                b1 = 2.f * (K*K - 1);
                b2 = 1.f - K/q + K*K;
                a1 = b1;
                a2 = 1.f - V*K/q + K*K;
            }
            b0 /= D;
            b1 /= D;
            b2 /= D;
            a1 /= D;
            a2 /= D;
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;
        
        case FilterType::LowPass:
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            b0 = (1.f - cos_w0) / 2.f;
            b1 =  1.f - cos_w0;
            b2 = b0;
            
            a0 =  1.f + alpha;
            a1 = -2.f * cos_w0;
            a2 =  1.f - alpha;
            
            b0 /= a0;
            b1 /= a0;
            b2 /= a0;
            a1 /= a0;
            a2 /= a0;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;

        case FilterType::HighPass:
            w0 = 2.f * M_PI * frequency / fs;
            alpha = sinf(w0)/(2.f * q);
            cos_w0 = cosf(w0);
            
            b0 =        (1.f + cos_w0) / 2.f;
            b1 = -1.f * (1.f + cos_w0);
            b2 = b0;
            
            a0 =  1.f + alpha;
            a1 = -2.f * cos_w0;
            a2 =  1.f - alpha;
            
            b0 /= a0;
            b1 /= a0;
            b2 /= a0;
            a1 /= a0;
            a2 /= a0;
            
            filter.setCoefficients(b0, b1, b2, a1, a2);
            break;

        default:
            break;
    }
}

void MultiFilter::updateSampleRate(float newSampleRate) {
    fs = newSampleRate;
    updateCoefficients();
}

float MultiFilter::tick(float sample) {
    return filter.tick(sample); // Pings buffers for new data
}

void MultiFilter::changeFilterType(FilterType type) {
    fType = type;
    updateCoefficients();
}