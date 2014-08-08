//----------------------------------------------------------------------------------------------------------
// StageEnd.cpp :
// 2014
// Ivory Tsai
//----------------------------------------------------------------------------------------------------------

#include "StageEnd.h"

//----------------------------------------------------------------
//--class StageEnd
//-----------------------
static const char* PNG_VECTORY_DIR = "victory/%s.png";
static const char* PNG_GAMEOVER_DIR = "gameover/%s.png";
//-------------------------------------------
// Constructor
//-------------------------------------------
StageEnd::StageEnd()
{
	pBtn_ =NULL;
}

StageEnd::~StageEnd()
{
    clearAll();
}

bool StageEnd::init()
{
    if (!CCLayer::init())
        return false;

    return true;
}

CCLayer * StageEnd::create(const bool isVictory, CCMenuItemSprite * pBtn)
{
	StageEnd *pLayer = new StageEnd();
	if (pLayer && pLayer->init())
    {
		if (isVictory)
		{
			pLayer->showVictory();
		}else{
			pLayer->showGameOver();
		}
		pLayer->autorelease();
		pLayer->pBtn_ = pBtn;
    }
    else
    {
		delete pLayer;
		pLayer = NULL;
    }
	CC_ASSERT(pLayer);
	return pLayer;
}

void StageEnd::clearAll()
{
    sprite_vtr_.clear();
}

void StageEnd::showVictory()
{
	sprite_vtr_.clear();

	const float kDelayInSec = 1.0f;
	const float kTime_add = 0.08f;
	const float kKiraDelayTime_offset = 0.5;
	float KiraDelayTime = kDelayInSec + kKiraDelayTime_offset;

	float scale = 1.5f;
	float padding = 10.0f;
	CCString *pPath = NULL;

	//-------[V]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "v");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[I]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "i");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[C]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "c");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[T]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "t");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[O]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "o");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[R]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "r");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[Y]-------------
	pPath = CCString::createWithFormat(PNG_VECTORY_DIR, "y");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);


	doAimate(kDelayInSec,
		kTime_add,
		padding,
		scale,
		Tint_YELLOW);
}

void StageEnd::showGameOver()
{
	sprite_vtr_.clear();

	const float kDelayInSec = 1.0f;
    const float kTime_add = 0.08f;
    const float kKiraDelayTime_offset =0.5;
	float KiraDelayTime = kDelayInSec + kKiraDelayTime_offset;

    float scale=1.4f;
    float padding = 10.0f;
	CCString *pPath = NULL;

	//-------[G]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "g");
	createSprite(kDelayInSec, pPath->getCString(),
                             padding,scale);

    //-------[A]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "a");
	createSprite(kDelayInSec, pPath->getCString(),
                             padding,scale);

    //-------[M]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "m");
	createSprite(kDelayInSec, pPath->getCString(),
                             padding,scale);

    //-------[E]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "e");
	 createSprite(kDelayInSec, pPath->getCString(),
                             padding,scale);

	//-------[O]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "o");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);
   
	//-------[V]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "v");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[E]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "e");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	//-------[R]-------------
	pPath = CCString::createWithFormat(PNG_GAMEOVER_DIR, "r");
	createSprite(kDelayInSec, pPath->getCString(),
		padding, scale);

	doAimate(kDelayInSec,
                   kTime_add,
                   padding,
                   scale,
				   Tint_CYAN);
}

void StageEnd::doAimate(const float delayInSec,
                                         const float kDelayTime_add,
                                         const float padding,
                                         const float scale ,
										 Tint_COLOUR tintColour)
{
    float maxHeight = 0.0f;
	int total = sprite_vtr_.size();

	for (int i = 0; i<total; i++)
	{
		if (NULL != sprite_vtr_[i])
		{
			// get Max Height
			float h = sprite_vtr_[i]->getContentSize().height;
			if (h > maxHeight)
			{
				maxHeight = h;
			}
		}
	}

    float delayTime = delayInSec;
    float w_total=0.0f;
	float y = maxHeight / 2;
	float x_offset = 0.0f;
    int idx=0;
    bool is2ndLine=false;

	for (int i = 0; i<total; i++)
	{
		if (NULL != sprite_vtr_[i])
		{
			// set position
			float w = sprite_vtr_[i]->getContentSize().width;


			const CCPoint kTargetPos = ccp(x_offset + (w / 2) + padding, y);
			sprite_vtr_[i]->setPosition(kTargetPos);
			x_offset = x_offset + w + (padding * 2);

			// add animation to each Sprite
			sprite_vtr_[i]->setScale(0.1f);
			sprite_vtr_[i]->setOpacity(0);
			float actTime_1 = 0.3;
			float actTime_2 = 0.15;
			CCEaseSineOut * pScaleTo_1 = CCEaseSineOut::create(CCScaleTo::create(actTime_1, (scale + 0.6f)));
			CCScaleTo * pScaleTo_2 = CCScaleTo::create(actTime_2, scale);
			CCFadeIn * pFadeIn = CCFadeIn::create(actTime_1);


			CCSequence * pSeq;

			if (Tint_CYAN == tintColour)
			{
				CCTintTo * pTintTo_1 = CCTintTo::create(actTime_1, 210, 255, 255);
				CCTintTo * pTintTo_Back_2 = CCTintTo::create(actTime_2, 255, 255, 255);
				CCTintTo * pTintTo_3 = CCTintTo::create(0.15f, 210, 255, 255);
				CCTintTo * pTintTo_Back_4 = CCTintTo::create(0.15f, 255, 255, 255);


				pSeq = CCSequence::create(CCDelayTime::create(delayTime),
					CCSpawn::create(pFadeIn, pScaleTo_1, pTintTo_1, NULL),
					CCSpawn::create(pScaleTo_2, pTintTo_Back_2, NULL),
					CCDelayTime::create(0.3f),
					pTintTo_3, pTintTo_Back_4,
					NULL);
			}
			else if (Tint_YELLOW == tintColour)
			{
				CCTintTo * pTintTo_1 = CCTintTo::create(actTime_1, 255, 255, 0);
				CCTintTo * pTintTo_Back_2 = CCTintTo::create(actTime_2, 255, 255, 255);
				CCTintTo * pTintTo_3 = CCTintTo::create(0.15f, 255, 255, 0);
				CCTintTo * pTintTo_Back_4 = CCTintTo::create(0.15f, 255, 255, 255);


				pSeq = CCSequence::create(CCDelayTime::create(delayTime),
					CCSpawn::create(pFadeIn, pScaleTo_1, pTintTo_1, NULL),
					CCSpawn::create(pScaleTo_2, pTintTo_Back_2, NULL),
					CCDelayTime::create(0.3f),
					pTintTo_3, pTintTo_Back_4,
					NULL);
			}
			else
			{
				pSeq = CCSequence::create(CCDelayTime::create(delayTime),
					CCSpawn::createWithTwoActions(pFadeIn, pScaleTo_1),
					pScaleTo_2,
					NULL);
			}


			if ((total - 1) == i) //--- Enable button only for last one
			{
				//-- enable btn ----------------------
				CCCallFunc* pFunc = CCCallFunc::create(this, callfunc_selector(StageEnd::enableBtn));
				CCSequence * pAct = CCSequence::create(pSeq,pFunc,NULL);
				sprite_vtr_[i]->runAction(pAct);
			}
			else
			{
				sprite_vtr_[i]->runAction(pSeq);
			}

			delayTime = delayTime + kDelayTime_add;
			++idx;
		}
	}

	this->setContentSize(CCSize(x_offset, maxHeight));
	
}

 void StageEnd::createSprite(const float delayInSec,
                                         const char* pDir ,
                                         const float padding,
                                         const float scale)
{
	CCSprite * pSprite = CCSprite::create(pDir);
    if (NULL != pSprite )
    {
        // add each sprite to target layer
        this->addChild(pSprite);

        // add each sprite to target layer
        sprite_vtr_.push_back(pSprite);
    }
}

 //-------------------------------------------
 // enable button
 //-------------------------------------------
 void StageEnd::enableBtn()
 {
	 if (NULL != pBtn_)
	 {
		 pBtn_->setEnabled(true);
	 }
 }