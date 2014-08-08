//----------------------------------------------------------------------------------------------------------
// File:				StageEnd.h
// Author:				Tsai, Pei-Yu
// Date:				2014
//----------------------------------------------------------------------------------------------------------
#ifndef __STAGEEND__
#define __STAGEEND__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

//-----------------------------------------------------------------------------------------------------------------------------------
class StageEnd : public CCLayer
{
	public:
	    StageEnd();
	    virtual ~StageEnd();
 	   virtual bool init();

	   static cocos2d::CCLayer* create(const bool isVictory, CCMenuItemSprite * pBtn);
	
	private:
	   enum Tint_COLOUR
	   {
		   Tint_NONE,
		   Tint_CYAN,
		   Tint_YELLOW
	   };

	private:
		CCMenuItemSprite * pBtn_;

	private:
		void showVictory();
	    void showGameOver();

	    void clearAll();

	    void doAimate(const float delayInSec,
                        const float kDelayTime_add,
                        const float padding,
                        const float scale,
						Tint_COLOUR tintColour);

	   void createSprite(const float delayInSec,
							   const char* pDir,
							   const float padding,
							   const float scale);

	   void enableBtn();

	private:
   		std::vector<CCSprite *> sprite_vtr_;

};
//-----------------------------------------------------------------------------------------------------------------------------------
#endif //__STAGEEND__
