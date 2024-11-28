#pragma once

enum DisplayType
{
    MAIN,
    READ_PH,
    FEEDING,
};

class Display
{
public:
    void init();
    void show();
    void show(float data);
    void show(float data1, float data2);
    enum DisplayType currentDisplay = MAIN;
    void setDisplay(DisplayType dp);
    void showLoading();
    void clearDisplay();
};