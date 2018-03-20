/*
  ==============================================================================

    PluginLookAndFeel.cpp
    Created: 14 Feb 2018 2:16:44pm
    Author:  Andrew Cloud

  ==============================================================================
*/

#include "PluginLookAndFeel.h"


PluginLookAndFeel::PluginLookAndFeel()
{
};

PluginLookAndFeel::~PluginLookAndFeel()
{
}

void PluginLookAndFeel::drawLinearSlider (Graphics& g,
                       int x, int y,
                       int width, int height,
                       float sliderPos,
                       float minSliderPos,
                       float maxSliderPos,
                       const Slider::SliderStyle style,
                       Slider& slider)
{
    g.fillAll(slider.findColour(Slider::backgroundColourId));
    
    if (style == Slider::LinearVertical)
    {
        if (slider.isVertical()) {
            g.setColour(slider.findColour(Slider::trackColourId));
            g.fillRect(x + 3*width/8, y + (int) sliderPos, width/4, height);
        }
        
        else {  // Incomplete and untested, not used in this plugin
            g.setColour(slider.findColour(Slider::trackColourId));
            g.fillRect(x, y, (int) sliderPos - x, height/2);
        }
    }
    else if (style == Slider::LinearHorizontal)
    {
        if (slider.isHorizontal()) {
            g.setColour(slider.findColour(Slider::trackColourId));
            g.fillRect(x, y + height/4, (int) sliderPos - x, height/2);
        }
    }
}

void PluginLookAndFeel::drawRotarySlider (Graphics& g,
                        int x, int y,
                        int width, int height,
                        float sliderPosProportional,    // 0. - 1.f
                        float rotaryStartAngle,
                        float rotaryEndAngle,
                        Slider& slider)
{
    g.fillAll(slider.findColour(Slider::backgroundColourId));

    rotaryPath.startNewSubPath((float) x, (float) y);
    if (sliderPosProportional < 0.5f) {
        rotaryPath.addArc(
            (float)x, (float)y,
            (float)width, (float)height,
            (1.f - (2.f * sliderPosProportional)) * -3 * M_PI_4, 0,     // 0 is top of arc
            true
        );
    }
    else {
        rotaryPath.addArc(
            (float)x, (float)y,
            (float)width, (float)height,
            0, ((sliderPosProportional - 0.5f) * 2.f) * 3 * M_PI_4,
            true
        );
    }
    PathStrokeType(16.f).createStrokedPath(rotaryPath, rotaryPath);     // Turns single line path to an outline (path now has width)
    
    // Transforms to fit rotary inside width and height
    rotaryPath.applyTransform(AffineTransform::scale(0.8f));
    rotaryPath.applyTransform(
        AffineTransform::translation(
            (float)((width - (4*width/5))/2), (float)((height - (4*height/5))/2)
    ));
    
    g.setColour(slider.findColour(Slider::trackColourId));
    g.fillPath(rotaryPath);
    
    g.drawLine((float) x + (width/2), (float) y, (float) x + (width/2), (float) y + (height/2));
    
    rotaryPath.clear();
}