#include "HelloWorldScene.h"
#include "StageEnd.h"

USING_NS_CC;

const int  ZVALUE_GAMEEND = 100;
const int  TAG_VICTORY = 100;
const int  TAG_GAMEOVER = 101;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	pBtn_Victory_=NULL;
	//-----------------------------------------------------------
	//[UI �ʒu�̕␳(�C��)]
	// ���R�FOpenGL�̍��W��Y������AX�������A���������_�ɂȂ�܂��B
	//�ł��̂ŁA��ʃT�C�Y��designSize (1024X512)�ɕς��ƁA�S����UI�z�u�ʒu������܂��B
	//�␳(�C��)���@�F
	//��ʃT�C�Y(_screenSize)���璆�S�_(_screenCenter)��T���āA���S�_�����_�Ƃ��āA
	//UI�̈ʒu�𒆐S�_����t�Z���Ĕz�u���܂��B
	//----- get screen size and find the center -----------------
	screenSize_ = CCDirector::sharedDirector()->getWinSize();////��ʃT�C�Y
	screenCenter_ = CCPoint(screenSize_.width / 2, screenSize_.height / 2);//���S�_
	//-----------------------------------------------------------

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);


	show_Victory();
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

//==================================================================================
//---for Victory animation-----------
//---------------------------------------------
void HelloWorld::show_Victory()
{
	bool isVictory = true;

	//-- create a big button----------
	CCLayerColor* layerBtn1 = CCLayerColor::create(ccc4(200, 200, 200, 100), screenSize_.width, screenSize_.height);
	CCLayerColor* layerBtn2 = CCLayerColor::create(ccc4(200, 200, 200, 200), screenSize_.width, screenSize_.height);

	pBtn_Victory_ = CCMenuItemSprite::create(layerBtn1, layerBtn2, this, menu_selector(HelloWorld::CallBack_Victory));

	pBtn_Victory_->setEnabled(false);

	CCMenu * pMenu = CCMenu::create(pBtn_Victory_, NULL);
	pMenu->setAnchorPoint(CCPoint(0.5f, 0.5f));
	pMenu->setPosition(screenCenter_);
	this->addChild(pMenu, ZVALUE_GAMEEND);

	//-----------StageEnd Layer--------------
	CCLayer * pStageEnd = StageEnd::create(isVictory, pBtn_Victory_);
	pStageEnd->setPosition(CCPoint(screenCenter_.x - (pStageEnd->getContentSize().width / 2),
									screenCenter_.y - (pStageEnd->getContentSize().height / 2)));
	this->addChild(pStageEnd, ZVALUE_GAMEEND, TAG_VICTORY);
}

//==================================================================================
//  Victory
//---------------------------------------------------------------------
void HelloWorld::CallBack_Victory(CCObject* pSender)
{
	CCLayer * pStageEnd = (CCLayer *) this->getChildByTag(TAG_VICTORY);
	pStageEnd->removeFromParentAndCleanup(true);
	pBtn_Victory_->removeFromParentAndCleanup(true);
	pBtn_Victory_ = NULL;
	show_Victory();
}
