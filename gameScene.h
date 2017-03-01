#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include"cocos2d.h"
#include"card.h"
#define MOVEHEIGHT 20 //�˿������ƶ��ĸ߶�
#define INTERVAL 35 //�˿�֮��ļ��
#define STARTY 40 //�˿˵ױ߸߶�
#define MENUTAG 40 //menu��ǩ
#define PLAYER1TAG 41//����˿˱�ǩ
#define PLAYER2TAG 42
#define PLAYER3TAG 43
enum Turn {
	player1,
	player2,
	player3
};
enum CardsType
{
	SingleCard,
	Pair,
	Triplet,
	TripletWithAnAttachedCard,
	TripletWithAnAttachedPair,
	Sequence,
	SequenceOfPairs,
	SequenceOfTriplets,
	SequenceOfTripletsWithAttachedCards,
	SequenceOfTripletsWithAttachedPairs,
	Bomb,
	Rocket,
	QuadplexSet,
	QuadPlexSets,
	Invalid,
};

class GameScene : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameScene);
	static cocos2d::Scene* createScene();
	void createCards();
	void shuffleCards();
	void discardCards();
	void sortCards();
	void displayCards();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	CardsType getCardsType(cocos2d::Vector<Card*> &cards);
	bool isSingleCard(cocos2d::Vector<Card*> &cards);
	bool isSingleCard(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isPair(cocos2d::Vector<Card*> &cards);
	bool isPair(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isTriplet(cocos2d::Vector<Card*> &cards);
	bool isTriplet(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isTripletWithAnAttachedCard(cocos2d::Vector<Card*> &cards);
	bool isTripletWithAnAttachedCard(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isTripletWithAnAttachedPair(cocos2d::Vector<Card*> &cards);
	bool isTripletWithAnAttachedPair(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isSequence(cocos2d::Vector<Card*> &cards);
	bool isSequence(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isSequenceOfPairs(cocos2d::Vector<Card*> &cards);
	bool isSequenceOfPairs(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isSequenceOfTriplets(cocos2d::Vector<Card*> &cards);
	bool isSequenceOfTriplets(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isSequenceOfTripletsWithAttachedCards(cocos2d::Vector<Card*> &cards);
	bool isSequenceOfTripletsWithAttachedCards(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isSequenceOfTripletsWithAttachedPairs(cocos2d::Vector<Card*> &cards);
	bool isSequenceOfTripletsWithAttachedPairs(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isBomb(cocos2d::Vector<Card*> &cards);
	bool isBomb(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isRocket(cocos2d::Vector<Card*> &cards);
	bool isRocket(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isQuadplexSet(cocos2d::Vector<Card*> &cards);
	bool isQuadplexSet(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	bool isQuadPlexSets(cocos2d::Vector<Card*> &cards);
	bool isQuadPlexSets(cocos2d::Vector<Card*>::iterator begin, cocos2d::Vector<Card*>::iterator end);
	cocos2d::Sprite* makeMenuItem(std::string bg, std::string word1, std::string word2);
	void moveCards();
	void adjustCards();
	bool hintCards(cocos2d::Vector<Card*> &cards);
	void AICards(cocos2d::Vector<Card*> &cards);
	void AIplayer2(float);
	void AIplayer3(float);
    cocos2d::Menu* makeMenu();
	void myTurn(float dt);
	cocos2d::Vector<Card*> hint(cocos2d::Vector<Card*> & playerCards);
	bool compare(cocos2d::Vector<Card*> lhs, cocos2d::Vector<Card*> rhs);
private:
	int startTouchNum;
	float startx;
	cocos2d::Vector<Card*> allCards;
	cocos2d::Vector<Card*> player1Cards;
	cocos2d::Vector<Card*> player2Cards;
	cocos2d::Vector<Card*> player3Cards;
	cocos2d::Vector<Card*> landlordCards;
	cocos2d::Vector<Card*> selectCards;
	cocos2d::Vector<Card*> otherCards;
	cocos2d::Menu* turnMenu;
	cocos2d::Vector<Card*> put1;
	cocos2d::Vector<Card*> put2;
	cocos2d::Vector<Card*> put3;
	Turn turn;
	Turn big;
};
#endif
