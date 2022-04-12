#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace::std;

#define NO_STRING_ID 1
#define MATERIAL_ID 2
#define INSTRUMENT_TYPE_ID 3

typedef enum MATERIAL{
    P_WOOD = 0,
    P_METAL,
    P_PLASTIC,
} P_MATERIAL;

typedef enum STRING_TYPE{
    P_1_STRING = 0,
    P_2_STRING,
    P_4_STRING,
    P_8_STRING,
    P_16_STRING,
} P_STRING_TYPE;

typedef enum INSTRUMENT_TYPE{
    P_GUITAR = 0,
    P_VIOLON,
    P_MINT,
} P_INSTRUMENT_TYPE;

class InstrumentSpec {
    private:
        map<int,int> properties;
    public:
        InstrumentSpec()
        {
            cout << "Create new instrument spec" << endl;
        }
        InstrumentSpec(map<int, int> Properties)
        {
            properties = Properties;
        }
        map<int, int> getProperties() const
        {
            return properties;
        }
        bool matches(map<int, int> Properties);
};

bool InstrumentSpec::matches(map<int, int> Properties)
{
    bool match;
    match = true;
    for (const auto& prop : Properties)
    {
        auto it = properties.find(prop.first);
        if ( it != properties.end())
        {
            if (prop.second != it->second)
            {
                match = false;
                break;
            }
        }
        else
        {
            match = false;
            break;
        }
    }
    return match;
}

class Instrument {
    private:
        string serialNumber;
        double price;
        InstrumentSpec spec;
    public:
        Instrument(string SerialNumber, double Price, InstrumentSpec Spec)
        {
            serialNumber = SerialNumber;
            price = Price;
            spec = Spec;
        }
        string getSerialNumber() const
        {
            return serialNumber;
        }
        double getPrice() const
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
        InstrumentSpec getSpec() const
        {
            return spec;
        }
        void setSpec(InstrumentSpec Spec)
        {
            spec = Spec;
        }        
};

class Inventory {
    private:
        vector<Instrument> inventory;
    public:
        Inventory()
        {
            cout << "Create a new shop" << endl;
        }
        void addInstrument(string SerialNumber, double Price, InstrumentSpec Spec);
        vector<Instrument> search(InstrumentSpec);
        void listAllInstrument();
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
        if (instrument.getSpec().matches(Spec.getProperties()) == true)
        {
            result.push_back(instrument);
        }
    }
    return result;
}

void Inventory::listAllInstrument()
{
    for (const auto& instrument: inventory)
    {
        cout << "Serial number: " << instrument.getSerialNumber() << " Price: " << instrument.getPrice() << endl; 
    }
}

int main()
{
    /* Create inventory */
    Inventory newInventory;
    map<int, int> newSpec1{ {INSTRUMENT_TYPE_ID, P_GUITAR}, {NO_STRING_ID,P_16_STRING}, {MATERIAL_ID,P_WOOD} }; 
    map<int, int> newSpec2{ {INSTRUMENT_TYPE_ID, P_VIOLON}, {NO_STRING_ID,P_1_STRING}, {MATERIAL_ID,P_METAL} }; 
    map<int, int> newSpec3{ {INSTRUMENT_TYPE_ID, P_MINT}, {NO_STRING_ID,P_8_STRING}, {MATERIAL_ID,P_PLASTIC} };

    newInventory.addInstrument("123", 50, InstrumentSpec(newSpec1)); 
    newInventory.addInstrument("abc", 100, InstrumentSpec(newSpec2)); 
    newInventory.addInstrument("xyz", 150, InstrumentSpec(newSpec3));

    /* List all instruments in the inventory */
    newInventory.listAllInstrument();

}