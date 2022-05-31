#include <stdio.h>
#include <string.h>

#define TransportationText(TYPE) char name[20];\
double speed;\
double distance;\
int (*price)(struct TYPE*);\
double (*time)(struct TYPE*)

typedef struct car_s {
    int oilPrice;
    int parkPrice;
    int tolls;
    TransportationText(car_s);
} car_t;

int CarPrice(car_t* obj){
    int hun_kilo = (obj->distance + 50) / 100;
    int price = hun_kilo * obj->tolls + hun_kilo * 10 * obj->oilPrice + obj->parkPrice;
    return price;
}

double CarTime(car_t* obj){
    return obj->distance / obj->speed;
}

void CarCreate(car_t *obj){
    strcpy(obj->name, "Car");
    obj->speed = 100;
    obj->price = CarPrice;
    obj->time = CarTime;
} 

typedef struct motor_s{
    int oilPrice;
    TransportationText(motor_s);
} motor_t;

int MotorPrice(motor_t* obj){
    int hun_kilo = (obj->distance + 50) / 100;
    int price = hun_kilo * (obj->oilPrice * 4);
    return price;
}

double MotorTime(motor_t* obj){
    return obj->distance / obj->speed;
}

void MotorCreate(motor_t *obj){
    strcpy(obj->name, "Scooter");
    obj->speed = 50;
    obj->price = MotorPrice;
    obj->time = MotorTime;
}  

typedef struct bus_s{
    int fee;
    int extra;
    TransportationText(bus_s);
} bus_t;

int BusPrice(bus_t* obj){
    int price = obj->fee;
    int dis = obj->distance - 100;
    price += ((dis + 49) / 50) * obj->extra ;
    return price;
}

double BusTime(bus_t* obj){
    return obj->distance / obj->speed;
}

void BusCreate(bus_t *obj){
    strcpy(obj->name, "Intercity Bus");
    obj->speed = 75;
    obj->price = BusPrice;
    obj->time = BusTime;
}  

typedef struct bike_s{
    int fee;
    TransportationText(bike_s);
} bike_t;

int BikePrice(bike_t* obj){
    int price = obj->fee;
    return price;
}

double BikeTime(bike_t* obj){
    return obj->distance / obj->speed;
}

void BikeCreate(bike_t *obj){
    strcpy(obj->name, "Bike");
    obj->speed = 20;
    obj->price = BikePrice;
    obj->time = BikeTime;
}  

int main () {
    int distance, tPrice, price, final_price, flag = 0;
    double time, min_time = 999999;
    char name[20];
    car_t car;
    motor_t motor;
    bus_t bus;
    bike_t bike;
    CarCreate(&car);
    MotorCreate(&motor);
    BusCreate(&bus);
    BikeCreate(&bike);


    scanf("%d %d", &distance, &tPrice);
    scanf("%d %d %d", &car.oilPrice, &car.parkPrice, &car.tolls);
    scanf("%d", &bike.fee);
    scanf("%d %d", &bus.fee, &bus.extra);
    scanf("%d", &motor.oilPrice);
    
    bus.distance = car.distance = motor.distance = bike.distance = distance;

    price = bus.price(&bus);
    time = bus.time(&bus);
    if (price <= tPrice && time < min_time) {
        flag = 1;
        min_time = time;
        strcpy(name, bus.name);
        final_price = price;
    }   
    
    price = car.price(&car);
    time = car.time(&car);
    if (price <= tPrice && time < min_time) {
        flag = 1;
        min_time = time;
        strcpy(name, car.name);
        final_price = price;
    }   
    
    price = motor.price(&motor);
    time = motor.time(&motor);
    if (price <= tPrice && time < min_time) {
        flag = 1;
        min_time = time;
        strcpy(name, motor.name);
        final_price = price;
    }   
    
    price = bike.price(&bike);
    time = bike.time(&bike);
    if (price <= tPrice && time < min_time) {
        flag = 1;
        min_time = time;
        strcpy(name, bike.name);
        final_price = price;
    }   
    
    if (flag == 0)  printf("No Transportation");
    else {
        printf("%s\n", name);
        printf("%d\n", final_price);
        printf("%.2lf", min_time);
    }

    return 0;
}
