#include <iostream>

#include <hazelcast/client/HazelcastClient.h>

using namespace hazelcast::client;
using namespace std;

class MyMapListener : public EntryListener<int, int> {
public:
    virtual void entryAdded(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void entryRemoved(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void entryUpdated(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void entryEvicted(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void entryExpired(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void entryMerged(const EntryEvent<int, int> &event) {
        cout << event << endl;
    }

    virtual void mapEvicted(const MapEvent &event) {
        cout << event << endl;
    }

    virtual void mapCleared(const MapEvent &event) {
        cout << event << endl;
    }
};

int main() {
    try {
        ClientConfig config;
        config.setProperty("hazelcast_client_heartbeat_timeout", "10");
        HazelcastClient client(config);

        IMap<int, int> map = client.getMap<int, int>("MyMap");
        MyMapListener listener;
        map.addEntryListener(listener, true);
        while (true) {
            int key = rand();
            int value = rand();

            int probability = key % 3;
            switch (probability) {
                case 0:
                    map.put(key, value);
                    cout << "Put " << key << " -> " << value << endl;
                    break;
                case 1:
                    map.remove(key);
                    cout << "Removed " << key << endl;
                    break;
                case 2: {
                    boost::shared_ptr<int> result = map.get(key);
                    cout << "Get value for key " << key << endl;
                    break;
                }
            }
            sleep(1);
        }
    } catch (hazelcast::client::exception::IException &e) {
        cout << "Caught expected exception " << e.what() << ". Test is ending gracefully. " << endl;
    }

    return 0;
}
