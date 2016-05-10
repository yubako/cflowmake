#ifndef _CY_LOOP_COLOR_H
#define _CY_LOOP_COLOR_H

class CyFlowLoopColor 
{
    private:
        unsigned int *_rgb;
        unsigned int  _idx;

    public:
        CyFlowLoopColor()
        {
            this->_idx = 0;
            this->_rgb = new unsigned int[16];
            this->_rgb[0] = 0xA3BCE2;
            this->_rgb[1] = 0xCFA7CD;
            this->_rgb[2] = 0xA59ACA;
            this->_rgb[3] = 0xCF7250;
            this->_rgb[4] = 0x007B43;
            this->_rgb[5] = 0xA7366D;
        }

        ~CyFlowLoopColor()
        {
            delete[] this->_rgb;
        }

        unsigned int get()
        {
            return this->_rgb[this->_idx++];
        }

        void reset()
        {
            this->_idx = 0;
        }
};

#endif
