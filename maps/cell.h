#pragma once

class cell
{
private:
    int q, r, s;
public:
    cell(int q, int r, int s): q(q), r(r), s(s){}
    virtual char getType() = 0; // Pure virtual function to be overridden by derived classes
};

class emptycell: public cell
{
public:
    emptycell(int q, int r, int s): cell(q, r, s){}
    char getType() override;
};

class goldcell: public cell
{
private:
    int value;
public:
    goldcell(int q, int r, int s, int value): cell(q, r, s), value(value){}
    int getValue();
    char getType() override;
};

class shieldcell: public cell
{
private:
    bool available;
public:
    shieldcell(int q, int r, int s, bool available): cell(q, r, s), available(available){}
    bool isAvailable();
    char getType() override;
};

class deathcell: public cell
{
public:
    deathcell(int q, int r, int s): cell(q, r, s){}
    char getType() override;
};

class cellFactory
{
public:
    static cell* createCell(int q, int r, int s, char value)
    {
        if (value == 'S')
        {
            return new shieldcell(q, r, s, true); // Assuming true is a placeholder for available
        }
        else if (value == 'D')
        {
            return new deathcell(q, r, s);
        }
        else if (value >= '0' && value <= '9')
        {
            return new goldcell(q, r, s, value - '0'); // Assuming value is a digit character for gold value
        }
        else
        {
            return new emptycell(q, r, s); // Default to empty cell for any other character
        }
    }
};
