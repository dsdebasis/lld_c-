#include<iostream>
#include<string>
using namespace std;

//Stratefy interface for walk

class RunningRobot{
    public:
        virtual void walk() = 0;
        virtual ~RunningRobot() {}
};

class NormalRunning: public RunningRobot{
    public:
        void walk() override{
            cout << "robot running at normal speed " << endl;
        }
     
};

class FastRunning: public RunningRobot{
    public:
        void walk() override{
            cout << "robot running at fast speed " << endl;
        }
};

class ChatRobot{
    public:
        virtual void chat()=0;
        virtual ~ChatRobot() {}
};

class FreeChat: public ChatRobot{
    public:
        void chat() override{
            cout << "free chat robot is chating" << endl;
        }
};
class PaidChat: public ChatRobot{
    public:
        void chat() override{
            cout << "Paid  chat robot is chating" << endl;
        }
};

class DancingRobot{
    public:
    virtual ~DancingRobot(){}
    virtual void dance()=0;
};

class ManipuriDance: public DancingRobot{
    public:
    void dance() override{
        cout << " ManipuriDance is performed by robot" << endl;

    }
};

class OdishiDance:public DancingRobot{
    public:
    void dance() override{
        cout << " OdishiDance is performed by robot" << endl;

    }
};
//Robot Base class

class Robot{
    protected:
        RunningRobot* runAble;
        ChatRobot* chatAble;
        DancingRobot* danceAble;

    public:
        Robot(RunningRobot* run,ChatRobot* chat,DancingRobot* dance){
              this->runAble = run;
              this->chatAble = chat;
              this->danceAble = dance;
        }

    void run(){
        runAble->walk();
    }
    void chat(){
          chatAble->chat();
    }
    void dance(){
        danceAble->dance();
    }

    virtual void projection()=0;

};

class NormalRobo:public Robot{
    public:
    NormalRobo(RunningRobot* r,ChatRobot* c ,DancingRobot* d):Robot(r,c,d){}

    void projection() override{
         cout << "Show casing all the normal features" <<endl;   
    }
};

class PremiumRobo:public Robot{
      public:
      PremiumRobo(RunningRobot* r,ChatRobot* c, DancingRobot* d ): Robot(r,c,d){}  
      void projection() override{
        cout <<"Premium Robot features on" << endl;
      }
};

int main(){
    Robot *robot1 = new NormalRobo(new NormalRunning(),new FreeChat(),new OdishiDance());
    
    robot1->run();
    robot1->chat();
    robot1->dance();
    robot1->projection();

    cout << "end --------------------->" << endl;

    Robot *r2 = new PremiumRobo(new FastRunning(),new PaidChat(),new ManipuriDance());

    r2->chat();
    r2->dance();
    r2->run();

    return 0;
}