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
            this->_rgb[0] = 0x0033ff;
            this->_rgb[1] = 0x00ffff;
            this->_rgb[2] = 0x009900;
            this->_rgb[3] = 0x330000;
            this->_rgb[4] = 0x6600ff;
            this->_rgb[5] = 0x663333;
            this->_rgb[6] = 0x660000;
            this->_rgb[7] = 0xff9900;
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
