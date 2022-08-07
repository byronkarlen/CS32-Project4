#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;

//A base class for all the games Objects
class Actor : public GraphObject{
public:
    Actor(StudentWorld* myWorld, int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0);
    
    void setLiveStatus(bool b);
    bool getLiveStatus() const;
    
    StudentWorld* getWorld() const;
    
    virtual char getID() const = 0;
    
    //Default annoy function on an actor does nothing
    virtual void annoy(int howMuch){}
    
    virtual ~Actor(){}
    
    virtual void doSomething() = 0;

private:
    StudentWorld* m_world;
    bool m_isAlive;
};

class Earth : public Actor{
public:
    Earth(StudentWorld* myWorld, int startX, int startY);
    
    //Earth doesn't do anything
    virtual void doSomething(){}
    virtual char getID() const;
    
};

class Character : public Actor{
public:
    Character(StudentWorld* myWorld, int imageID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0);
    
    virtual void annoy(int howMuch);
    
    virtual ~Character(){}
private:
    int m_hitPoints;
};

class TunnelMan : public Character{
public:
    TunnelMan(StudentWorld* myWorld);
    
    virtual void doSomething();
    
    virtual char getID() const;
private:
    int m_numWater;
    int m_numSonarCharges;
    int m_numNuggets;
};


class Boulder : public Actor{
public:
    Boulder(StudentWorld* myWorld, int startX, int startY);
    virtual char getID() const;
    virtual void doSomething();
private:
    int state; //0 for stable, 1 for waiting, 2 for falling
    int ticksElapsed;
    
    bool boulderCanFall() const;
};

//class Squirt : public Actor{
//public:
//    Squirt(StudentWorld* myWorld, TunnelMan* owner);
//    virtual char getID() const;
//    virtual void doSomething();
//private:
//    int travelDistance;
//};


#endif // ACTOR_H_
 
