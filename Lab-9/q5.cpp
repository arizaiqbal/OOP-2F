#include <iostream>
using namespace std;
class Activity {
public:
    virtual double calculateCaloriesBurned() = 0; 
    virtual ~Activity() {} 
};
class Running : public Activity {
private:
    double distance; 
    double time;     
public:
    Running(double d, double t) : distance(d), time(t) {}
    double calculateCaloriesBurned() override {
        return (distance * 50); 
    }
};
class Cycling : public Activity {
private:
    double speed; 
    double time;  
public:
    Cycling(double s, double t) : speed(s), time(t) {}
    double calculateCaloriesBurned() override {
        return (speed * time * 15); 
    }
};
int main(){
    

    Running run(5, 30); 
    Cycling cycle(20, 1); 
    return 0;
}