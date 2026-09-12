class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
    virtual Car* createVehicle() override {
        Car* res = new Car;
        return res;
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here
    virtual Bike* createVehicle() override {
        Bike* res = new Bike;
        return res;
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here
    virtual Truck* createVehicle() override {
        Truck * res = new Truck;
        return res;
    }
};
