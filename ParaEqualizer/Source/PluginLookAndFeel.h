/*
  ==============================================================================

    PluginLookAndFeel.h
    Created: 14 Feb 2018 2:16:44pm
    Author:  Andrew Cloud

  ==============================================================================
*/

#ifndef PLUGINLOOKANDFEEL_H_INCLUDED
#define PLUGINLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PluginLookAndFeel: public LookAndFeel_V2
{
public:
    PluginLookAndFeel();
    virtual ~PluginLookAndFeel();

    /* Slider styling */
    virtual void drawLinearSlider (Graphics& g,
                           int x, int y,
                           int width, int height,
                           float sliderPos,
                           float minSliderPos,
                           float maxSliderPos,
                           const Slider::SliderStyle style,
                           Slider& slider);

    virtual void drawRotarySlider (Graphics& g,
                           int x, int y,
                           int width, int height,
                           float sliderPosProportional,
                           float rotaryStartAngle,
                           float rotaryEndAngle,
                           Slider& slider);
private:
    Path rotaryPath;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginLookAndFeel)
};

#endif  // PLUGINLOOKANDFEEL_H_INCLUDED
