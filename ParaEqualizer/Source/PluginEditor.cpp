/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[/Headers]

#include "PluginEditor.h"


//[/MiscUserDefs]

//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // GROUP 1
    addAndMakeVisible (f1Group = new GroupComponent ("Band1 Group",
                                                     TRANS("Band1")));
    f1Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f1Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f1FreqSlider = new Slider ("Band1 Frequency"));
    f1FreqSlider->setRange (20, 20000, 0);
    f1FreqSlider->setSkewFactorFromMidPoint(1000.0);   // Skew for logarithmic
    f1FreqSlider->setTextBoxIsEditable(true);
    f1FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f1FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1FreqSlider->addListener (this);

    addAndMakeVisible (f1GainDbSlider = new Slider ("Band1 Gain"));
    f1GainDbSlider->setRange (-24, 24, 0.1);
    f1GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f1GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1GainDbSlider->addListener (this);

    addAndMakeVisible (f1QSlider = new Slider ("Band1 Q"));
    f1QSlider->setRange (0.1, 10, 0.01);
    f1QSlider->setSliderStyle (Slider::LinearHorizontal);
    f1QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f1QSlider->addListener (this);

    addAndMakeVisible (outputGainDbSlider = new Slider ("Output Gain"));
    outputGainDbSlider->setRange (-24, 24, 0.1);
    outputGainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    outputGainDbSlider->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    outputGainDbSlider->addListener (this);

    // GROUP 2
    addAndMakeVisible (f2Group = new GroupComponent ("Band2 Group",
                                                     TRANS("Band2")));
    f2Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f2Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f2FreqSlider = new Slider ("Band2 Frequency"));
    f2FreqSlider->setRange (20, 20000, 0);
    f2FreqSlider->setSkewFactorFromMidPoint(1000.0);   // Set Skew for Logarithmic
    f2FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f2FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2FreqSlider->addListener (this);

    addAndMakeVisible (f2GainDbSlider = new Slider ("Band2 Gain"));
    f2GainDbSlider->setRange (-24, 24, 0.1);
    f2GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f2GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2GainDbSlider->addListener (this);

    addAndMakeVisible (f2QSlider = new Slider ("Band2 Q"));
    f2QSlider->setRange (0.1, 10, 0.01);
    f2QSlider->setSliderStyle (Slider::LinearHorizontal);
    f2QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f2QSlider->addListener (this);

    // GROUP 3
    addAndMakeVisible (f3Group = new GroupComponent ("Band3 Group",
                                                     TRANS("Band3")));
    f3Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f3Group->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (f3FreqSlider = new Slider ("Band3 Frequency"));
    f3FreqSlider->setRange (20, 20000, 0);
    f3FreqSlider->setSkewFactorFromMidPoint(1000.0);   // Set Skew for Logarithmic
    f3FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f3FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3FreqSlider->addListener (this);

    addAndMakeVisible (f3GainDbSlider = new Slider ("Band3 Gain"));
    f3GainDbSlider->setRange (-24, 24, 0.1);
    f3GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f3GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3GainDbSlider->addListener (this);

    addAndMakeVisible (f3QSlider = new Slider ("Band3 Q"));
    f3QSlider->setRange (0.1, 10, 0.01);
    f3QSlider->setSliderStyle (Slider::LinearHorizontal);
    f3QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f3QSlider->addListener (this);
    
    // GROUP 4
    addAndMakeVisible (f4Group = new GroupComponent ("Band4 Group",
                                                     TRANS("Band4")));
    f4Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f4Group->setColour (GroupComponent::textColourId, Colours::white);
    
    addAndMakeVisible (f4FreqSlider = new Slider ("Band4 Frequency"));
    f4FreqSlider->setRange (20, 20000, 0);
    f4FreqSlider->setSkewFactorFromMidPoint(1000.0);       // Set skew logarithmic
    f4FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f4FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f4FreqSlider->addListener (this);
    
    addAndMakeVisible (f4GainDbSlider = new Slider ("Band4 Gain"));
    f4GainDbSlider->setRange (-24, 24, 0.1);
    f4GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f4GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f4GainDbSlider->addListener (this);
    
    addAndMakeVisible (f4QSlider = new Slider ("Band4 Q"));
    f4QSlider->setRange (0.1, 10, 0.01);
    f4QSlider->setSliderStyle (Slider::LinearHorizontal);
    f4QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f4QSlider->addListener (this);
    
    // GROUP 5
    addAndMakeVisible (f5Group = new GroupComponent ("Band5 Group",
                                                     TRANS("Band5")));
    f5Group->setColour (GroupComponent::outlineColourId, Colour (0xffbbbbbb));
    f5Group->setColour (GroupComponent::textColourId, Colours::white);
    
    addAndMakeVisible (f5FreqSlider = new Slider ("Band5 Frequency"));
    f5FreqSlider->setRange (20, 20000, 0);
    f5FreqSlider->setSkewFactorFromMidPoint(1000.0);       // Set skew logarithmic
    f5FreqSlider->setSliderStyle (Slider::LinearHorizontal);
    f5FreqSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f5FreqSlider->addListener (this);
    
    addAndMakeVisible (f5GainDbSlider = new Slider ("Band5 Gain"));
    f5GainDbSlider->setRange (-24, 24, 0.1);
    f5GainDbSlider->setSliderStyle (Slider::LinearHorizontal);
    f5GainDbSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f5GainDbSlider->addListener (this);
    
    addAndMakeVisible (f5QSlider = new Slider ("Band5 Q"));
    f5QSlider->setRange (0.1, 10, 0.01);
    f5QSlider->setSliderStyle (Slider::LinearHorizontal);
    f5QSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    f5QSlider->addListener (this);
    
    // COMBO BOX VALUES
    addAndMakeVisible (f1TypeComboBox = new ComboBox ("Band1 Type"));
    f1TypeComboBox->setEditableText (false);
    f1TypeComboBox->setJustificationType (Justification::centred);
    f1TypeComboBox->setTextWhenNothingSelected (TRANS("Band Type"));
    f1TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f1TypeComboBox->addItem (TRANS("Low Shelf"), 1);
    f1TypeComboBox->addItem (TRANS("HighPass"), 2); // original value = 5
    f1TypeComboBox->addListener (this);

    addAndMakeVisible (f2TypeComboBox = new ComboBox ("Band2 Type"));
    f2TypeComboBox->setEditableText (false);
    f2TypeComboBox->setJustificationType (Justification::centred);
    f2TypeComboBox->setTextWhenNothingSelected (TRANS("Band Type"));
    f2TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f2TypeComboBox->addItem (TRANS("Peak"), 1);         // Original ID 2
    //f2TypeComboBox->addItem (TRANS("Low Shelf"), 2);
    f2TypeComboBox->addListener (this);

    addAndMakeVisible (f3TypeComboBox = new ComboBox ("Band3 Type"));
    f3TypeComboBox->setEditableText (false);
    f3TypeComboBox->setJustificationType (Justification::centred);
    f3TypeComboBox->setTextWhenNothingSelected (TRANS("Band Type"));
    f3TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f3TypeComboBox->addItem (TRANS("Peak"), 1);             // original 2
    f3TypeComboBox->addListener (this);
    
    addAndMakeVisible (f4TypeComboBox = new ComboBox ("Band4 Type"));
    f4TypeComboBox->setEditableText (false);
    f4TypeComboBox->setJustificationType (Justification::centred);
    f4TypeComboBox->setTextWhenNothingSelected (TRANS("Band Type"));
    f4TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f4TypeComboBox->addItem (TRANS("Peak"), 1);
    //f4TypeComboBox->addItem (TRANS("High Shelf"), 2);
    f4TypeComboBox->addListener (this);
    
    addAndMakeVisible (f5TypeComboBox = new ComboBox ("Band5 Type"));
    f5TypeComboBox->setEditableText (false);
    f5TypeComboBox->setJustificationType (Justification::centred);
    f5TypeComboBox->setTextWhenNothingSelected (TRANS("Band Type"));
    f5TypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    f5TypeComboBox->addItem (TRANS("High Shelf"), 1);       // original = 3
    f5TypeComboBox->addItem (TRANS("LowPass"), 2);          // original = 4
    f5TypeComboBox->addListener (this);
    
    // GUI TEXT
    f1FreqSlider->setTextValueSuffix(" Hz");
    f2FreqSlider->setTextValueSuffix(" Hz");
    f3FreqSlider->setTextValueSuffix(" Hz");
    f4FreqSlider->setTextValueSuffix(" Hz");
    f5FreqSlider->setTextValueSuffix(" Hz");
    
    f1GainDbSlider->setTextValueSuffix(" dB");
    f2GainDbSlider->setTextValueSuffix(" dB");
    f3GainDbSlider->setTextValueSuffix(" dB");
    f4GainDbSlider->setTextValueSuffix(" dB");
    f5GainDbSlider->setTextValueSuffix(" dB");
    
    f1QSlider->setTextValueSuffix(" (Q)");
    f2QSlider->setTextValueSuffix(" (Q)");
    f3QSlider->setTextValueSuffix(" (Q)");
    f4QSlider->setTextValueSuffix(" (Q)");
    f5QSlider->setTextValueSuffix(" (Q)");
    
    outputGainDbSlider->setTextValueSuffix(" dB");

    // Instantiate Filter Types
    f1TypeComboBox->setSelectedId(1);       // LS
    f2TypeComboBox->setSelectedId(1);       // Peak
    f3TypeComboBox->setSelectedId(1);       // Peak
    f4TypeComboBox->setSelectedId(1);       // Peak
    f5TypeComboBox->setSelectedId(1);       // HS

    // DOUBLE-CLICK RETURN VALUES
    f1FreqSlider->setDoubleClickReturnValue(true, 800.f);
    f2FreqSlider->setDoubleClickReturnValue(true, 2000.f);
    f3FreqSlider->setDoubleClickReturnValue(true, 8000.f);
    f4FreqSlider->setDoubleClickReturnValue(true, 12000.f);
    f5FreqSlider->setDoubleClickReturnValue(true, 15000.f);

    f1QSlider->setDoubleClickReturnValue(true, 0.71f);
    f2QSlider->setDoubleClickReturnValue(true, 0.71f);
    f3QSlider->setDoubleClickReturnValue(true, 0.71f);
    f4QSlider->setDoubleClickReturnValue(true, 0.71f);
    f5QSlider->setDoubleClickReturnValue(true, 0.71f);

    f1GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f2GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f3GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f4GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    f5GainDbSlider->setDoubleClickReturnValue(true, 0.f);
    
    outputGainDbSlider->setDoubleClickReturnValue(true, 0.f);
    //[/UserPreSize]

    //setSize (480, 232);

    setSize (800, 300);

    //[Constructor] Custom stuff

    // Uncomment to apply custom styling from PluginLookAndFeel
    //LookAndFeel::setDefaultLookAndFeel(&otherLookAndFeel);
    //LookAndFeel::setDefaultLookAndFeel(&pluginLookAndFeel);

    startTimer (50);
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[/Destructor_pre]
    
    f1Group = nullptr;
    f1FreqSlider = nullptr;
    f1GainDbSlider = nullptr;
    f1QSlider = nullptr;
    
    outputGainDbSlider = nullptr;
    
    f2Group = nullptr;
    f2FreqSlider = nullptr;
    f2GainDbSlider = nullptr;
    f2QSlider = nullptr;
    
    f3Group = nullptr;
    f3FreqSlider = nullptr;
    f3GainDbSlider = nullptr;
    f3QSlider = nullptr;
    
    f4Group = nullptr;
    f4FreqSlider = nullptr;
    f4GainDbSlider = nullptr;
    f4QSlider = nullptr;
    
    f5Group = nullptr;
    f5FreqSlider = nullptr;
    f5GainDbSlider = nullptr;
    f5QSlider = nullptr;
    
    f1TypeComboBox = nullptr;
    f2TypeComboBox = nullptr;
    f3TypeComboBox = nullptr;
    f4TypeComboBox = nullptr;
    f5TypeComboBox = nullptr;


    //[Destructor] Custom stuff
    deleteAllChildren();    // Just in case missing something (maybe unneeded)
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{

    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[/UserPreResize]

    // MUST MAKE ADJUSTABLE (NOT SET TO PIXEL)

    f1Group->setBounds (0, 0, 160, 200);
    f1FreqSlider->setBounds (8, 104, 142, 40);
    f1GainDbSlider->setBounds (8, 56, 144, 40);
    f1QSlider->setBounds (8, 152, 144, 40);
    
    outputGainDbSlider->setBounds (240 - (448 / 2), 200, 448, 32);
    
    f2Group->setBounds (160, 0, 160, 200);
    f2FreqSlider->setBounds (168, 104, 142, 40);
    f2GainDbSlider->setBounds (168, 56, 144, 40);
    f2QSlider->setBounds (168, 152, 144, 40);
    
    f3Group->setBounds (320, 0, 160, 200);
    f3FreqSlider->setBounds (328, 104, 142, 40);
    f3GainDbSlider->setBounds (328, 56, 144, 40);
    f3QSlider->setBounds (328, 152, 144, 40);
    
    f4Group->setBounds (480, 0, 160, 200);
    f4FreqSlider->setBounds (488, 104, 144, 40);
    f4GainDbSlider->setBounds (488, 56, 144, 40);
    f4QSlider->setBounds (488, 152, 144, 40);
    
    f5Group->setBounds (640, 0, 160, 200);
    f5FreqSlider->setBounds (648, 104, 142, 40);
    f5GainDbSlider->setBounds (648, 56, 144, 40);
    f5QSlider->setBounds (648, 152, 144, 40);
    
    f1TypeComboBox->setBounds (16, 24, 128, 24);
    f2TypeComboBox->setBounds (176, 24, 128, 24);
    f3TypeComboBox->setBounds (336, 24, 128, 24);
    f4TypeComboBox->setBounds (496, 24, 128, 24);
    f5TypeComboBox->setBounds (656, 24, 128, 24);

    
    //[/UserResized]
}

void PluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    //GROUP 1
    if (sliderThatWasMoved == f1FreqSlider)
    {
        //[UserSliderCode_f1FreqSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f1FreqSlider]
    }
    else if (sliderThatWasMoved == f1GainDbSlider)
    {
        //[UserSliderCode_f1GainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f1GainDbSlider]
    }
    else if (sliderThatWasMoved == f1QSlider)
    {
        //[UserSliderCode_f1QSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f1QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f1QSlider]
    }
    
    // OUTPUT GAIN
    else if (sliderThatWasMoved == outputGainDbSlider)
    {
        //[UserSliderCode_outputGainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::outputGainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_outputGainDbSlider]
    }
    
    
    // Group 2
    else if (sliderThatWasMoved == f2FreqSlider)
    {
        //[UserSliderCode_f2FreqSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f2FreqSlider]
    }
    else if (sliderThatWasMoved == f2GainDbSlider)
    {
        //[UserSliderCode_f2GainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f2GainDbSlider]
    }
    else if (sliderThatWasMoved == f2QSlider)
    {
        //[UserSliderCode_f2QSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f2QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f2QSlider]
    }
    
    // Group 3
    else if (sliderThatWasMoved == f3FreqSlider)
    {
        //[UserSliderCode_f3FreqSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f3FreqSlider]
    }
    else if (sliderThatWasMoved == f3GainDbSlider)
    {
        //[UserSliderCode_f3GainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f3GainDbSlider]
    }
    else if (sliderThatWasMoved == f3QSlider)
    {
        //[UserSliderCode_f3QSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f3QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f3QSlider]
    }
    
    // Group 4
    else if (sliderThatWasMoved == f4FreqSlider)
    {
        //[UserSliderCode_f4FreqSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f4FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f4FreqSlider]
    }
    else if (sliderThatWasMoved == f4GainDbSlider)
    {
        //[UserSliderCode_f4GainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f4GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f4GainDbSlider]
    }
    else if (sliderThatWasMoved == f4QSlider)
    {
        //[UserSliderCode_f4QSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f4QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f4QSlider]
    }
    
    // Group 5
    else if (sliderThatWasMoved == f5FreqSlider)
    {
        //[UserSliderCode_f5FreqSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f5FreqParam,
            (sliderThatWasMoved->getValue() - 20) / 19980
        );
        //[/UserSliderCode_f5FreqSlider]
    }
    else if (sliderThatWasMoved == f5GainDbSlider)
    {
        //[UserSliderCode_f5GainDbSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f5GainParam,
            (sliderThatWasMoved->getValue() + 24) / 48
        );
        //[/UserSliderCode_f5GainDbSlider]
    }
    else if (sliderThatWasMoved == f5QSlider)
    {
        //[UserSliderCode_f5QSlider] -- slider handling code here
        processor.setParameterNotifyingHost(
            PluginAudioProcessor::Parameters::f5QParam,
            (sliderThatWasMoved->getValue() - 0.1f) / 9.9f
        );
        //[/UserSliderCode_f5QSlider]
    }
    
    
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



void PluginAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]
    
    // COMBOBOX VALUES
    // 0 = Low Shelf    (0)
    // 1 = Peak         (0.2)
    // 2 = High Shelf   (0.4)
    // 3 = Lowpass      (0.6)
    // 4 = Highpass     (0.8)

    if (comboBoxThatHasChanged == f1TypeComboBox)
    {
        //[UserComboBoxCode_f1TypeComboBox]
        
        // DISPLAY COMBO BOX VALUES
        //String alert = ("Selected ID: " + (String)comboBoxThatHasChanged->getSelectedId() + "\nItem Index: " + (String)comboBoxThatHasChanged->getSelectedItemIndex() +                     "\nNumItems: " + (String)comboBoxThatHasChanged->getNumItems());
        //AlertWindow::showMessageBoxAsync (AlertWindow::InfoIcon, "Console Output", alert);
        // END DISPLAY
        
        // COMBO BOX SWITCH
        switch(comboBoxThatHasChanged->getSelectedItemIndex())
        {
            case 0:     // 1st Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f1TypeParam, 0);  // Make Low shelf
                f1GainDbSlider->setEnabled(true);
                f1QSlider->setEnabled(true);
                break;
            case 1:     // 2nd Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f1TypeParam, 0.8);    // Make Highpass
                f1GainDbSlider->setEnabled(false);
                f1QSlider->setValue(0.707f);      // RESET TO 0.7
                f1QSlider->setEnabled(false);
                break;
            default:
                break;
        }
        
        //[/UserComboBoxCode_f1TypeComboBox]
    }
    
    // Group 2
    else if (comboBoxThatHasChanged == f2TypeComboBox)
    {
        //[UserComboBoxCode_f2TypeComboBox]
        
        // Info Sent values:
        // 0   = Low Shelf
        // 0.2 = Peak
        // 0.4 = High Shelf
        // 0.6 = Lowpass
        // 0.8 = Highpass
        
        switch(comboBoxThatHasChanged->getSelectedItemIndex())
        {
            case 0:     // 1st Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f2TypeParam, 0.2);  // Make Peak
                break;
            //case 1:     // 2nd Item
                //processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f2TypeParam, 0);    // Make Low Shelf
                //break;
            default:
                break;
        }
        
        // ORIGINAL
        //processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f2TypeParam,(float)comboBoxThatHasChanged->getSelectedItemIndex() / (float) comboBoxThatHasChanged->getNumItems());
        
        //[/UserComboBoxCode_f2TypeComboBox]
    }
    
    // Group 3
    else if (comboBoxThatHasChanged == f3TypeComboBox)
    {
        //[UserComboBoxCode_f3TypeComboBox]
        //processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f3TypeParam,(float)comboBoxThatHasChanged->getSelectedItemIndex() / (float) comboBoxThatHasChanged->getNumItems());
        
        switch(comboBoxThatHasChanged->getSelectedItemIndex())
        {
            case 0:     // 1st Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f3TypeParam, 0.2);  // Make PEAK
                break;
            default:
                break;
        }

        //[/UserComboBoxCode_f3TypeComboBox]
    }
    
    // Group 4
    else if (comboBoxThatHasChanged == f4TypeComboBox)
    {
        //[UserComboBoxCode_f4TypeComboBox]
        
        // Info Sent values:
        // 0   = Low Shelf
        // 0.2 = Peak
        // 0.4 = High Shelf
        // 0.6 = Lowpass
        // 0.8 = Highpass
        
        //COMBO BOX
        switch(comboBoxThatHasChanged->getSelectedItemIndex())
        {
            case 0:     // 1st Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f4TypeParam, 0.2);  // Make Peak
                break;
            //case 1:     // 2nd Item
                //processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f4TypeParam, 0.4);    // Make High shelf
                //break;
            default:
                break;
        }
        
        //[/UserComboBoxCode_f2TypeComboBox]
    }
    
    // Group 5
    else if (comboBoxThatHasChanged == f5TypeComboBox)
    {
        //[UserComboBoxCode_f5TypeComboBox]
        
        // Info Sent values:
        // 0   = Low Shelf
        // 0.2 = Peak
        // 0.4 = High Shelf
        // 0.6 = Lowpass
        // 0.8 = Highpass
        
        switch(comboBoxThatHasChanged->getSelectedItemIndex())
        {
            case 0:     // 1st Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f5TypeParam, 0.4);  // Make High shelf
                f5GainDbSlider->setEnabled(true);
                f5QSlider->setEnabled(true);
                break;
            case 1:     // 2nd Item
                processor.setParameterNotifyingHost(PluginAudioProcessor::Parameters::f5TypeParam, 0.6);    // Make Lowpass
                f5GainDbSlider->setEnabled(false);
                f5QSlider->setValue(0.707f);      // RESET TO 0.7
                f5QSlider->setEnabled(false);
                break;
            default:
                break;
        }
        
        //[/UserComboBoxCode_f5TypeComboBox]
    }
    
    
    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginAudioProcessorEditor::timerCallback()
{
    // Set UI values to match any changes made by host automation
    // Timer conflicts cause UI stuttering, this is due to the values not being mapped back
    PluginAudioProcessor& ourProcessor = getProcessor();

    
    // GROUP 1
    f1FreqSlider->setValue(
        20 + (ourProcessor.uf1Freq * 19980),
        dontSendNotification
    );
    f1QSlider->setValue(
        0.1f + (ourProcessor.uf1Q * 9.9f),
        dontSendNotification
    );
    f1GainDbSlider->setValue(
        -24 + (ourProcessor.uf1GainDb * 48),
        dontSendNotification
    );
    // Controls Band Type
    f1TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf1Type * (float) f1TypeComboBox->getNumItems()),
        dontSendNotification
    );
    
    // GROUP 2
    f2FreqSlider->setValue(
        20 + (ourProcessor.uf2Freq * 19980),
        dontSendNotification
    );
    f2QSlider->setValue(
        0.1f + (ourProcessor.uf2Q * 9.9f),
        dontSendNotification
    );
    f2GainDbSlider->setValue(
        -24 + (ourProcessor.uf2GainDb * 48),
        dontSendNotification
    );
    // Controls Bandtype
    f2TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf2Type * (float) f2TypeComboBox->getNumItems()),
        dontSendNotification
    );
    
    // Group 3
    f3FreqSlider->setValue(
        20 + (ourProcessor.uf3Freq * 19980),
        dontSendNotification
    );
    f3QSlider->setValue(
        0.1f + (ourProcessor.uf3Q * 9.9f),
        dontSendNotification
    );
    f3GainDbSlider->setValue(
        -24 + (ourProcessor.uf3GainDb * 48),
        dontSendNotification
    );
    // Controls Band Type
    f3TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf3Type * (float) f3TypeComboBox->getNumItems()),
        dontSendNotification
    );
    
    //NEW
    // Group 4
    f4FreqSlider->setValue(
        20 + (ourProcessor.uf4Freq * 19980),
        dontSendNotification
    );
    f4QSlider->setValue(
        0.1f + (ourProcessor.uf4Q * 9.9f),
        dontSendNotification
    );
    f4GainDbSlider->setValue(
        -24 + (ourProcessor.uf4GainDb * 48),
        dontSendNotification
    );
    // Controls Band Type
    f4TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf4Type * (float) f4TypeComboBox->getNumItems()),
        dontSendNotification
    );
    
    // Group 5
    f5FreqSlider->setValue(
        20 + (ourProcessor.uf5Freq * 19980),
        dontSendNotification
    );
    f5QSlider->setValue(
        0.1f + (ourProcessor.uf5Q * 9.9f),
        dontSendNotification
    );
    f5GainDbSlider->setValue(
        -24 + (ourProcessor.uf5GainDb * 48),
        dontSendNotification
    );
    // Controls Band Type
    f5TypeComboBox->setSelectedItemIndex(
        (int) (ourProcessor.uf5Type * (float) f5TypeComboBox->getNumItems()),
        dontSendNotification
    );
    
    //OUTPUT GAIN
    outputGainDbSlider->setValue(
         -24 + (ourProcessor.uOutputGainDb * 48),
        dontSendNotification
    );
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PluginAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="480" initialHeight="232">
  <BACKGROUND backgroundColour="ff222222"/>
  <GROUPCOMPONENT name="Filter1 Group" id="3e3623464cd19898" memberName="f1Group"
                  virtualName="" explicitFocusOrder="0" pos="0 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter1"/>
  <SLIDER name="Filter1 Frequency" id="9c1b5f965c3496b1" memberName="f1FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="8 104 142 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter1 Gain" id="ca46285293b766fb" memberName="f1GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="8 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter1 Q" id="6b3feafb481c407c" memberName="f1QSlider"
          virtualName="" explicitFocusOrder="0" pos="8 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Output Gain" id="c1a935f737dd219f" memberName="outputGainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="240c 200 448 32" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="Filter2 Group" id="7cd375bda4a5ec1a" memberName="f2Group"
                  virtualName="" explicitFocusOrder="0" pos="160 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter2"/>
  <SLIDER name="Filter2 Frequency" id="1c2a04d934cb6c9c" memberName="f2FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="168 104 142 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter2 Gain" id="b8f88db88714ea6b" memberName="f2GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="168 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter2 Q" id="51264063d9828a77" memberName="f2QSlider"
          virtualName="" explicitFocusOrder="0" pos="168 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="Filter3 Group" id="ef8795c31b8e473f" memberName="f3Group"
                  virtualName="" explicitFocusOrder="0" pos="320 0 160 200" outlinecol="ffbbbbbb"
                  textcol="ffffffff" title="Filter3"/>
  <SLIDER name="Filter3 Frequency" id="833854691aa41e24" memberName="f3FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="328 104 144 40" min="20"
          max="20000" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter3 Gain" id="709ddea6d5c7b347" memberName="f3GainDbSlider"
          virtualName="" explicitFocusOrder="0" pos="328 56 144 40" min="-24"
          max="24" int="0.10000000000000000555" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Filter3 Q" id="70ef231f74f55ac0" memberName="f3QSlider"
          virtualName="" explicitFocusOrder="0" pos="328 152 144 40" min="0.10000000000000000555"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Filter1 Type" id="adb4886bc59b10c3" memberName="f1TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="16 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter2 Type" id="7fb9885b1b601bb1" memberName="f2TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="176 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Filter3 Type" id="2396ee60b755337b" memberName="f3TypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="336 24 128 24" editable="0"
            layout="36" items="Low Shelf&#10;Peak&#10;High Shelf&#10;LowPass&#10;HighPass"
            textWhenNonSelected="Filter Type" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
