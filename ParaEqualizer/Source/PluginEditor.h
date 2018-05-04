/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once
// Headers
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "PluginLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Timer,
                                    public SliderListener,
                                    public ComboBoxListener
{
public:
    //==============================================================================
    PluginAudioProcessorEditor (PluginAudioProcessor& p);
    ~PluginAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginAudioProcessor& processor;

    PluginAudioProcessor& getProcessor() const
    {
        return static_cast<PluginAudioProcessor&> (processor);
    }

    //LookAndFeel_V1 otherLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> f1Group;
    ScopedPointer<Slider> f1FreqSlider;
    ScopedPointer<Slider> f1GainDbSlider;
    ScopedPointer<Slider> f1QSlider;
    ScopedPointer<Slider> outputGainDbSlider;
    ScopedPointer<GroupComponent> f2Group;
    ScopedPointer<Slider> f2FreqSlider;
    ScopedPointer<Slider> f2GainDbSlider;
    ScopedPointer<Slider> f2QSlider;
    ScopedPointer<GroupComponent> f3Group;
    ScopedPointer<Slider> f3FreqSlider;
    ScopedPointer<Slider> f3GainDbSlider;
    ScopedPointer<Slider> f3QSlider;
    
    ScopedPointer<GroupComponent> f4Group;
    ScopedPointer<Slider> f4FreqSlider;
    ScopedPointer<Slider> f4GainDbSlider;
    ScopedPointer<Slider> f4QSlider;
    
    ScopedPointer<GroupComponent> f5Group;
    ScopedPointer<Slider> f5FreqSlider;
    ScopedPointer<Slider> f5GainDbSlider;
    ScopedPointer<Slider> f5QSlider;
    
    ScopedPointer<ComboBox> f1TypeComboBox;
    ScopedPointer<ComboBox> f2TypeComboBox;
    ScopedPointer<ComboBox> f3TypeComboBox;
    ScopedPointer<ComboBox> f4TypeComboBox;
    ScopedPointer<ComboBox> f5TypeComboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
