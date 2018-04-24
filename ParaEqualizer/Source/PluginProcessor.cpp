/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "FilterType.h"
#include <math.h>


//==============================================================================
PluginAudioProcessor::PluginAudioProcessor()
{
    uf1Freq = DEFAULT_U_F1_FREQ;
    uf2Freq = DEFAULT_U_F2_FREQ;
    uf3Freq = DEFAULT_U_F3_FREQ;
    // NEW
    uf4Freq = DEFAULT_U_F4_FREQ;
    uf5Freq = DEFAULT_U_F5_FREQ;
    uf1Q = uf2Q = uf3Q = uf4Q = uf5Q = DEFAULT_U_FILTER_Q;
    
    uf1GainDb = uf2GainDb = uf3GainDb = uf4GainDb = uf5GainDb = DEFAULT_U_FILTER_GAIN_DB;
    uf1Type = DEFAULT_U_F1_TYPE;
    uf2Type = DEFAULT_U_F2_TYPE;
    uf3Type = DEFAULT_U_F3_TYPE;
    // NEW
    uf4Type = DEFAULT_U_F4_TYPE;
    uf5Type = DEFAULT_U_F5_TYPE;
    uOutputGainDb = DEFAULT_U_OUTPUT_GAIN_DB;
    
    af1Freq = DEFAULT_A_F1_FREQ;
    af2Freq = DEFAULT_A_F2_FREQ;
    af3Freq = DEFAULT_A_F3_FREQ;
    //NEW
    af4Freq = DEFAULT_A_F4_FREQ;
    af5Freq = DEFAULT_A_F5_FREQ;
    af1Q = af2Q = af3Q = af4Q = af5Q = DEFAULT_A_FILTER_Q;
    
    af1GainDb = af2GainDb = af3GainDb = af4GainDb = af5GainDb = DEFAULT_A_FILTER_GAIN_DB;
    af1Type = DEFAULT_A_F1_TYPE;
    af2Type = DEFAULT_A_F2_TYPE;
    af3Type = DEFAULT_A_F3_TYPE;
    af4Type = DEFAULT_A_F4_TYPE;
    af5Type = DEFAULT_A_F5_TYPE;
    aOutputGain = DEFAULT_A_OUTPUT_GAIN;
}

PluginAudioProcessor::~PluginAudioProcessor()
{
}

String PluginAudioProcessor::filterTypeString(FilterType type) {
    switch (type) {
        case FilterType::LowShelf:      return String("LowShelf");
        case FilterType::Peak:          return String("Peak");
        case FilterType::HighShelf:     return String("HighShelf");
        case FilterType::LowPass:       return String("LowPass");
        case FilterType::HighPass:      return String("HighPass");
        default:                        return String::empty;
    }
}


//==============================================================================
const String PluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int PluginAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float PluginAudioProcessor::getParameter (int index)                    // Must return 0-1.f
{
    switch (index) {
        case outputGainParam:   return uOutputGainDb;
        case f1FreqParam:       return uf1Freq;
        case f1GainParam:       return uf1GainDb;
        case f1QParam:          return uf1Q;
        case f1TypeParam:       return uf1Type;
        case f2FreqParam:       return uf2Freq;
        case f2GainParam:       return uf2GainDb;
        case f2QParam:          return uf2Q;
        case f2TypeParam:       return uf2Type;
        case f3FreqParam:       return uf3Freq;
        case f3GainParam:       return uf3GainDb;
        case f3QParam:          return uf3Q;
        case f3TypeParam:       return uf3Type;
            //NEW
        case f4FreqParam:       return uf4Freq;
        case f4GainParam:       return uf4GainDb;
        case f4QParam:          return uf4Q;
        case f4TypeParam:       return uf4Type;
            
        case f5FreqParam:       return uf5Freq;
        case f5GainParam:       return uf5GainDb;
        case f5QParam:          return uf5Q;
        case f5TypeParam:       return uf5Type;
        default:                return 0.0f;
    }
}

void PluginAudioProcessor::setParameter (int index, float newValue)     // newValue always 0-1.f
{
    switch (index) {
        case outputGainParam:
            uOutputGainDb = newValue;
            aOutputGain = powf(10, (-24 + (uOutputGainDb) * 48)/ 20);
            break;

        case f1FreqParam:
            uf1Freq = newValue;
            af1Freq = 20 + (uf1Freq * 19980);
            filterL1->frequency = af1Freq;
            filterL1->updateCoefficients();
            filterR1->frequency = af1Freq;
            filterR1->updateCoefficients();
            break;
        case f1QParam:
            uf1Q = newValue;
            af1Q = 0.1f + (uf1Q * 9.9f);
            filterL1->q = af1Q;
            filterL1->updateCoefficients();
            filterR1->q = af1Q;
            filterR1->updateCoefficients();
            break;
        case f1GainParam:
            uf1GainDb = newValue;
            af1GainDb = -24 + (uf1GainDb * 48);
            filterL1->dbGain = af1GainDb;
            filterL1->updateCoefficients();
            filterR1->dbGain = af1GainDb;
            filterR1->updateCoefficients();
            break;
        case f1TypeParam:
            uf1Type = newValue;
            af1Type = (FilterType) (int) (uf1Type * TOTAL_NUM_FILTERS);
            filterL1->changeFilterType(af1Type);
            filterR1->changeFilterType(af1Type);
            break;

        case f2FreqParam:
            uf2Freq = newValue;
            af2Freq = 20 + (uf2Freq * 19980);
            filterL2->frequency = af2Freq;
            filterL2->updateCoefficients();
            filterR2->frequency = af2Freq;
            filterR2->updateCoefficients();
            break;
        case f2QParam:
            uf2Q = newValue;
            af2Q = 0.1f + (uf2Q * 9.9f);
            filterL2->q = af2Q;
            filterL2->updateCoefficients();
            filterR2->q = af2Q;
            filterR2->updateCoefficients();
            break;
        case f2GainParam:
            uf2GainDb = newValue;
            af2GainDb = -24 + (uf2GainDb * 48);
            filterL2->dbGain = af2GainDb;
            filterL2->updateCoefficients();
            filterR2->dbGain = af2GainDb;
            filterR2->updateCoefficients();
            break;
        case f2TypeParam:
            uf2Type = newValue;
            af2Type = (FilterType) (int) (uf2Type * TOTAL_NUM_FILTERS);
            filterL2->changeFilterType(af2Type);
            filterR2->changeFilterType(af2Type);
            break;

        case f3FreqParam:
            uf3Freq = newValue;
            af3Freq = 20 + (uf3Freq * 19980);
            filterL3->frequency = af3Freq;
            filterL3->updateCoefficients();
            filterR3->frequency = af3Freq;
            filterR3->updateCoefficients();
            break;
        case f3QParam:
            uf3Q = newValue;
            af3Q = 0.1f + (uf3Q * 9.9f);
            filterL3->q = af3Q;
            filterL3->updateCoefficients();
            filterR3->q = af3Q;
            filterR3->updateCoefficients();
            break;
        case f3GainParam:
            uf3GainDb = newValue;
            af3GainDb = -24 + (uf3GainDb * 48);
            filterL3->dbGain = af3GainDb;
            filterL3->updateCoefficients();
            filterR3->dbGain = af3GainDb;
            filterR3->updateCoefficients();
            break;
        case f3TypeParam:
            uf3Type = newValue;
            af3Type = (FilterType) (int) (uf3Type * TOTAL_NUM_FILTERS);
            filterL3->changeFilterType(af3Type);
            filterR3->changeFilterType(af3Type);
            break;
            
            //NEW
        case f4FreqParam:
            uf4Freq = newValue;
            af4Freq = 20 + (uf4Freq * 19980);
            filterL4->frequency = af4Freq;
            filterL4->updateCoefficients();
            filterR4->frequency = af4Freq;
            filterR4->updateCoefficients();
            break;
        case f4QParam:
            uf4Q = newValue;
            af4Q = 0.1f + (uf4Q * 9.9f);
            filterL4->q = af4Q;
            filterL4->updateCoefficients();
            filterR4->q = af4Q;
            filterR4->updateCoefficients();
            break;
        case f4GainParam:
            uf4GainDb = newValue;
            af4GainDb = -24 + (uf4GainDb * 48);
            filterL4->dbGain = af4GainDb;
            filterL4->updateCoefficients();
            filterR4->dbGain = af4GainDb;
            filterR4->updateCoefficients();
            break;
        case f4TypeParam:
            uf4Type = newValue;
            af4Type = (FilterType) (int) (uf4Type * TOTAL_NUM_FILTERS);
            filterL4->changeFilterType(af4Type);
            filterR4->changeFilterType(af4Type);
            break;
            
        case f5FreqParam:
            uf5Freq = newValue;
            af5Freq = 20 + (uf5Freq * 19980);
            filterL5->frequency = af5Freq;
            filterL5->updateCoefficients();
            filterR5->frequency = af5Freq;
            filterR5->updateCoefficients();
            break;
        case f5QParam:
            uf5Q = newValue;
            af5Q = 0.1f + (uf5Q * 9.9f);
            filterL5->q = af5Q;
            filterL5->updateCoefficients();
            filterR5->q = af5Q;
            filterR5->updateCoefficients();
            break;
        case f5GainParam:
            uf5GainDb = newValue;
            af5GainDb = -24 + (uf5GainDb * 48);
            filterL5->dbGain = af5GainDb;
            filterL5->updateCoefficients();
            filterR5->dbGain = af5GainDb;
            filterR5->updateCoefficients();
            break;
        case f5TypeParam:
            uf5Type = newValue;
            af5Type = (FilterType) (int) (uf5Type * TOTAL_NUM_FILTERS);
            filterL5->changeFilterType(af5Type);
            filterR5->changeFilterType(af5Type);
            break;
    }
}

float PluginAudioProcessor::getParameterDefaultValue (int index)        // Must return 0-1.f
{
    switch (index) {
        case outputGainParam:       return DEFAULT_U_OUTPUT_GAIN_DB;
        case f1FreqParam:           return DEFAULT_U_F1_FREQ;
        case f1QParam:              return DEFAULT_U_FILTER_Q;
        case f1GainParam:           return DEFAULT_U_FILTER_GAIN_DB;
        case f1TypeParam:           return DEFAULT_U_F1_TYPE;
        case f2FreqParam:           return DEFAULT_U_F2_FREQ;
        case f2QParam:              return DEFAULT_U_FILTER_Q;
        case f2GainParam:           return DEFAULT_U_FILTER_GAIN_DB;
        case f2TypeParam:           return DEFAULT_U_F2_TYPE;
        case f3FreqParam:           return DEFAULT_U_F3_FREQ;
        case f3QParam:              return DEFAULT_U_FILTER_Q;
        case f3GainParam:           return DEFAULT_U_FILTER_GAIN_DB;
        case f3TypeParam:           return DEFAULT_U_F3_TYPE;
                // NEW
        case f4FreqParam:           return DEFAULT_U_F4_FREQ;
        case f4QParam:              return DEFAULT_U_FILTER_Q;
        case f4GainParam:           return DEFAULT_U_FILTER_GAIN_DB;
        case f4TypeParam:           return DEFAULT_U_F4_TYPE;
            
        case f5FreqParam:           return DEFAULT_U_F5_FREQ;
        case f5QParam:              return DEFAULT_U_FILTER_Q;
        case f5GainParam:           return DEFAULT_U_FILTER_GAIN_DB;
        case f5TypeParam:           return DEFAULT_U_F5_TYPE;
            
        default:                    return 0.0f;
    }
}

int PluginAudioProcessor::getParameterNumSteps (int index)
{
    switch (index) {
        case f1TypeParam:
        case f2TypeParam:
        case f3TypeParam:
        case f4TypeParam:
        case f5TypeParam:           return (int) FilterType::TotalNumFilters;
            
        default:                    return AudioProcessor::getDefaultNumParameterSteps();
    }
}

const String PluginAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case outputGainParam:   return String("Output Gain");
        case f1FreqParam:       return String("Filter1 Freq");
        case f1QParam:          return String("Filter1 Q");
        case f1GainParam:       return String("Filter1 Gain");
        case f1TypeParam:       return String("Filter1 Type");
        case f2FreqParam:       return String("Filter2 Freq");
        case f2QParam:          return String("Filter2 Q");
        case f2GainParam:       return String("Filter2 Gain");
        case f2TypeParam:       return String("Filter2 Type");
        case f3FreqParam:       return String("Filter3 Freq");
        case f3QParam:          return String("Filter3 Q");
        case f3GainParam:       return String("Filter3 Gain");
        case f3TypeParam:       return String("Filter3 Type");
            
            //NEW
        case f4FreqParam:       return String("Filter4 Freq");
        case f4QParam:          return String("Filter4 Q");
        case f4GainParam:       return String("Filter4 Gain");
        case f4TypeParam:       return String("Filter4 Type");
            
        case f5FreqParam:       return String("Filter5 Freq");
        case f5QParam:          return String("Filter5 Q");
        case f5GainParam:       return String("Filter5 Gain");
        case f5TypeParam:       return String("Filter5 Type");
            
        default:                return String::empty;
    }
}

const String PluginAudioProcessor::getParameterText (int index)
{
    switch (index) {
        case outputGainParam:   return String((-24 + (uOutputGainDb) * 48), 1) + "dB";
        case f1FreqParam:       return String(af1Freq, 0) + "Hz";
        case f1QParam:          return String(af1Q, 2);
        case f1GainParam:       return String(af1GainDb, 1) + "dB";
        case f1TypeParam:       return filterTypeString(af1Type);
        case f2FreqParam:       return String(af2Freq, 0) + "Hz";
        case f2QParam:          return String(af2Q, 2);
        case f2GainParam:       return String(af2GainDb, 1) + "dB";
        case f2TypeParam:       return filterTypeString(af2Type);
        case f3FreqParam:       return String(af3Freq, 0) + "Hz";
        case f3QParam:          return String(af3Q, 2);
        case f3GainParam:       return String(af3GainDb, 1) + "dB";
        case f3TypeParam:       return filterTypeString(af3Type);
            
            // NEW
        case f4FreqParam:       return String(af4Freq, 0) + "Hz";
        case f4QParam:          return String(af4Q, 2);
        case f4GainParam:       return String(af4GainDb, 1) + "dB";
        case f4TypeParam:       return filterTypeString(af4Type);
            
        case f5FreqParam:       return String(af5Freq, 0) + "Hz";
        case f5QParam:          return String(af5Q, 2);
        case f5GainParam:       return String(af5GainDb, 1) + "dB";
        case f5TypeParam:       return filterTypeString(af5Type);
            
        default:                return String(getParameter(index), 2);
    }
}

const String PluginAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PluginAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PluginAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PluginAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool PluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PluginAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double PluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PluginAudioProcessor::setCurrentProgram (int index)
{
}

const String PluginAudioProcessor::getProgramName (int index)
{
    return String();
}

void PluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that is needed
    fs = sampleRate;
    
    if (filterL1 == nullptr && filterL2 == nullptr && filterL3 == nullptr && filterL4 == nullptr && filterL4 == nullptr
        && filterR1 == nullptr && filterR2 == nullptr && filterR3 == nullptr && filterR4 == nullptr && filterR5 == nullptr)
    {
        // LEFT
        filterL1 = new MultiFilter(af1Type, sampleRate, af1Freq);
        filterL2 = new MultiFilter(af2Type, sampleRate, af2Freq);
        filterL3 = new MultiFilter(af3Type, sampleRate, af3Freq);
        // NEW
        filterL4 = new MultiFilter(af4Type, sampleRate, af4Freq);
        filterL5 = new MultiFilter(af5Type, sampleRate, af5Freq);
        
        // RIGHT
        filterR1 = new MultiFilter(af1Type, sampleRate, af1Freq);
        filterR2 = new MultiFilter(af2Type, sampleRate, af2Freq);
        filterR3 = new MultiFilter(af3Type, sampleRate, af3Freq);
        //NEW
        filterR4 = new MultiFilter(af4Type, sampleRate, af4Freq);
        filterR5 = new MultiFilter(af5Type, sampleRate, af5Freq);
    }
    else {
        filterL1->updateSampleRate(fs);
        filterL2->updateSampleRate(fs);
        filterL3->updateSampleRate(fs);
        filterL4->updateSampleRate(fs);
        filterL5->updateSampleRate(fs);
        
        filterR1->updateSampleRate(fs);
        filterR2->updateSampleRate(fs);
        filterR3->updateSampleRate(fs);
        filterR4->updateSampleRate(fs);
        filterR5->updateSampleRate(fs);
        
    }
}

void PluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void PluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // If sampleRate changes and not previously detected
    if (fs != getSampleRate()) {
        fs = getSampleRate();
        filterL1->updateSampleRate(fs);
        filterL2->updateSampleRate(fs);
        filterL3->updateSampleRate(fs);
        filterL4->updateSampleRate(fs);
        filterL5->updateSampleRate(fs);
        
        filterR1->updateSampleRate(fs);
        filterR2->updateSampleRate(fs);
        filterR3->updateSampleRate(fs);
        filterR4->updateSampleRate(fs);
        filterR5->updateSampleRate(fs);
    }
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // Added to avoid screaming feedback
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    float* leftChannel = buffer.getWritePointer(0);
    float* rightChannel = buffer.getWritePointer(1);
    for (int i = 0; i < buffer.getNumSamples(); i++) {
        leftChannel[i]  = aOutputGain * filterL5->tick(filterL4->tick(filterL3->tick(filterL2->tick(filterL1->tick(leftChannel[i])))));
        rightChannel[i] = aOutputGain * filterR5->tick(filterR4->tick(filterR3->tick(filterR2->tick(filterR1->tick(rightChannel[i])))));
        /*
        leftChannel[i]  = aOutputGain * filterL3->tick(filterL2->tick(filterL1->tick(leftChannel[i])));
        rightChannel[i] = aOutputGain * filterR3->tick(filterR2->tick(filterR1->tick(rightChannel[i])));
         */
    }
}

//==============================================================================
bool PluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if not supply an editor)
}

AudioProcessorEditor* PluginAudioProcessor::createEditor()
{
    return new PluginAudioProcessorEditor (*this);
}

//==============================================================================
void PluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginAudioProcessor();
}

