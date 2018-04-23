/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "BiQuad.h"
#include "FilterType.h"
#include "MultiFilter.h"


//==============================================================================
/**
*/
class PluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PluginAudioProcessor();
    ~PluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;
    float getParameterDefaultValue (int index) override;
    int getParameterNumSteps(int index) override;
    
    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    enum Parameters
    {
        f1FreqParam,
        f1GainParam,
        f1QParam,
        f1TypeParam,
        f2FreqParam,
        f2GainParam,
        f2QParam,
        f2TypeParam,
        f3FreqParam,
        f3GainParam,
        f3QParam,
        f3TypeParam,
        outputGainParam,
        totalNumParams
    };
    
    // Host/Control Values (0-1.f)
    float uf1Freq,      uf2Freq,        uf3Freq;
    float uf1Q,         uf2Q,           uf3Q;
    float uf1GainDb,    uf2GainDb,      uf3GainDb;
    float uf1Type,      uf2Type,        uf3Type;
    float uOutputGainDb;
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessor)
    
    // Default Algorithm Values
    const float DEFAULT_A_F1_FREQ = 800.f;
    const float DEFAULT_A_F2_FREQ = 2000.f;
    const float DEFAULT_A_F3_FREQ = 8000.f;
    const float DEFAULT_A_FILTER_Q = 0.71f;
    const float DEFAULT_A_FILTER_GAIN_DB = 0.f;
    const float DEFAULT_A_OUTPUT_GAIN = 1.f;
    
    //const FilterType DEFAULT_A_F1_TYPE = FilterType::LowShelf;
    //const FilterType DEFAULT_A_F1_TYPE = FilterType::HighPass;
    const FilterType DEFAULT_A_F1_TYPE = FilterType::Peak;
    
    const FilterType DEFAULT_A_F2_TYPE = FilterType::Peak;
    
    //const FilterType DEFAULT_A_F3_TYPE = FilterType::HighShelf;       
    //const FilterType DEFAULT_A_F3_TYPE = FilterType::LowPass;
    const FilterType DEFAULT_A_F3_TYPE = FilterType::Peak;

    const float TOTAL_NUM_FILTERS = (float) (int) FilterType::TotalNumFilters;
    
    // Default Host/Control Values (Must be 0-1.f mapping)
    const float DEFAULT_U_F1_FREQ           = (DEFAULT_A_F1_FREQ - 20) / 19980;
    const float DEFAULT_U_F2_FREQ           = (DEFAULT_A_F2_FREQ - 20) / 19980;
    const float DEFAULT_U_F3_FREQ           = (DEFAULT_A_F3_FREQ - 20) / 19980;
    const float DEFAULT_U_FILTER_Q          = (DEFAULT_A_FILTER_Q - 0.1f) / 9.9f;
    const float DEFAULT_U_FILTER_GAIN_DB    = 0.5f;
    const float DEFAULT_U_F1_TYPE           = (float) (int) DEFAULT_A_F1_TYPE / (float) (int) FilterType::TotalNumFilters;
    const float DEFAULT_U_F2_TYPE           = (float) (int) DEFAULT_A_F2_TYPE / (float) (int) FilterType::TotalNumFilters;
    const float DEFAULT_U_F3_TYPE           = (float) (int) DEFAULT_A_F3_TYPE / (float) (int) FilterType::TotalNumFilters;
    const float DEFAULT_U_OUTPUT_GAIN_DB    = 0.5f;
    
    // Algorithm Values
    float fs;           // Sampling Frequency
    
    float af1Freq,      af2Freq,        af3Freq;
    float af1Q,         af2Q,           af3Q;
    float af1GainDb,    af2GainDb,      af3GainDb;
    FilterType af1Type, af2Type,        af3Type;
    float aOutputGain;
    
    // Filters
    ScopedPointer<MultiFilter>
        filterL1, filterL2, filterL3,
        filterR1, filterR2, filterR3;
    
    String filterTypeString(FilterType type);
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
