#ifndef INPUT_H
#define INPUT_H


class Input
{
public:
    Input();
    void process();
    int get_last_key();
private:
    int last_key;
};

#endif // INPUT_H
