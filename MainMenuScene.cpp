//
// Created by anastasia on 08.05.17.
//

#include "GameScene.h"
#include "MainMenuScene.h"
USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(MainMenu::menuCloseCallback, this));

    closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    auto menuitem_1 = MenuItemFont::create("Play", CC_CALLBACK_1(MainMenu::Play, this));
    auto menuitem_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(MainMenu::Highscores, this));
    auto menuitem_3 = MenuItemFont::create("Help", CC_CALLBACK_1(MainMenu::Help, this));
    auto menuitem_4 = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenu::Exit, this));

    menuitem_1->setColor(ccc3(160, 32, 240)); menuitem_1->setFontSize(90);
    menuitem_2->setColor(ccc3(255, 0, 0));
    menuitem_3->setColor(ccc3(0, 0, 255));
    menuitem_4->setColor(ccc3(84, 84, 84));


    menuitem_1->setPosition(Point(visibleSize.width / 4, (visibleSize.height / 4) * 4));
    menuitem_2->setPosition(Point((visibleSize.width / 4), (visibleSize.height / 4) * 3));
    menuitem_3->setPosition(Point((visibleSize.width / 4), (visibleSize.height / 4) * 2));
    menuitem_4->setPosition(Point((visibleSize.width / 4), (visibleSize.height / 4) * 1));

    menu = Menu::create(menuitem_1,menuitem_2, menuitem_3, menuitem_4,  NULL);
    menu->alignItemsVertically();
    this->addChild(menu);

    //add background for game
    auto bgImage = Sprite::create("BG.png");
    bgImage->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add background image at z-position = -1, bottom of all
    // the z-position value is relative to parent
    this->addChild(bgImage, -1);
    // calculate the scaling factor to fill the screen size
    float rX = visibleSize.width / bgImage->getContentSize().width;
    float rY = visibleSize.height / bgImage->getContentSize().height;
    // set the scaling factor to the background image
    bgImage->setScaleX(rX);
    bgImage->setScaleY(rY);
    return true;
}

void MainMenu::Play(Ref *pSender)
{
    CCScene *mScene = GameScene::createScene();

    CCDirector::sharedDirector()->replaceScene(mScene);

}

void MainMenu::Highscores(Ref *pSender)
{
    CCLOG("BallDemo");

}
void MainMenu::Help(Ref *pSender)
{
    CCLOG("AninDemo");

}
void MainMenu::Exit(Ref *pSender)
{
    CCLOG("Play");

}



void MainMenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}