#pragma once
#include "BaseGUI.h"
#include "MainGUI.h"
#include "TemporalText.h"
#include "StaticText.h"

class MainGUI :
    public BaseGUI
{
public:
    MainGUI();
    ~MainGUI();
    std::unique_ptr<TemporalText>TrailLengthText;
    std::unique_ptr<TemporalText>WelcomeText;
    std::unique_ptr<TemporalText>SignatureText;

    std::unique_ptr<StaticText>ControlsText;
    std::unique_ptr<StaticText>ControlsText2;
};

