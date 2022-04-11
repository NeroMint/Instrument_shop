#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace::std;

class Inventory {
    private:
        vector<Instrument> inventory;
    public:
        void addInstrument(string SerialNumber, double Price, InstrumentSpec Spec);
        vector<Instrument> search(InstrumentSpec);
        Inventory()
        {
            cout << "Create a new shop" << endl;
        }
};

class Instrument {
    private:
        string serialNumber;
        double price;
        InstrumentSpec spec;
    public:
        string getSerialNumber()
        {
            return serialNumber;
        }
        double getPrice()
        {
            return price;
        }
        void setPrice(double Price)
        {
            price = Price;
        }
        void setSerialNumber(string SerialNumber)
        {
            serialNumber = SerialNumber;
        }
        InstrumentSpec getSpec()
        {
            return spec;
        }
        Instrument(string SerialNumber, double Price, InstrumentSpec Spec)
        {
            serialNumber = SerialNumber;
            price = Price;
            spec = Spec;
        }
        
};

class InstrumentSpec {
    private:
        map<int,string> properties;
    public:
        bool matches(InstrumentSpec);
        InstrumentSpec(map<int, string> Properties)
        {
            properties = Properties;
        } 
};

void Inventory::addInstrument(string SerialNumber, double Price, InstrumentSpec Spec)
{    
    Instrument newInstrument(SerialNumber, Price, Spec);
    inventory.push_back(newInstrument);
}

vector<Instrument> Inventory::search(InstrumentSpec Spec)
{
    vector<Instrument> result;
    for(const auto& instrument: inventory) 
    {
        if (instrument.getSpec().matches(Spec) == true)
        {
            result.push_back(instrument);
        }
    }
    return result;
}

