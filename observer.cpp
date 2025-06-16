#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ISubscriber{
    public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel {

    public:
       virtual void subscribe(ISubscriber* subscriber) = 0;
       virtual void unsubscribe(ISubscriber* subscriber) = 0;
       virtual void notifySubscribers() = 0;
       virtual ~IChannel() {}
};

class Channel : public IChannel{
    private:
        vector<ISubscriber*> subscribers;
        string channelName;
        string latestVideo;

    public:
        Channel(const string& name){
            this->channelName = name;
        }

        void subscribe(ISubscriber* subscriber) override{
            if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
                subscribers.push_back(subscriber);
            }
        }

        void unsubscribe(ISubscriber* subscriber) override{
            auto it = find(subscribers.begin(), subscribers.end(), subscriber);
            if (it != subscribers.end()) {
                subscribers.erase(it);
            }
        }

        void notifySubscribers() override{
            for (ISubscriber* sub : subscribers) {
                sub->update();
            }
        }

        void uploadVideo(const string& title) {
          latestVideo = title;
        cout << "\n[" << channelName << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
        }

        string getVideo(){
             return "\nCheckout our new Video : " + latestVideo + "\n";
        }
};
class Subscriber : public ISubscriber{
    private:
        string name;
        Channel* channel;
    public:
        Subscriber(const string& name, Channel* channel){
            this->name = name;
            this->channel = channel;
       
        }
        void update() override{
             cout << "Hey " << name << "," << this->channel->getVideo() << endl;
        }
        
};
int main(){
    Channel* channel = new Channel("Dhruv Rathe");

    Subscriber* sub1 = new Subscriber("John", channel);
    Subscriber* sub2 = new Subscriber("Jane", channel);

    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("Kya vijay mallya chor hey");

    channel->unsubscribe(sub1);

    channel->uploadVideo("dunia khatam hone wala he");
    return 0;
}