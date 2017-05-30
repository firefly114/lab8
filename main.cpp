#include <iostream>
#include <vector>
#include <progbase-cpp/net.h>

#include <request.h>
#include <response.h>
#include <actor.h>

using namespace std;
using namespace progbase::net;

#define BUFFER_LENGTH 10000

vector<Actor*> createActors(void);
void clearActors(vector<Actor*> Actors);

int main(int argc, char * argv[]){
    vector<Actor*> Actors = createActors();
	const int serverPort = atoi(argv[1]);
    TcpListener listener;
    NetMessage message(BUFFER_LENGTH);
    try {
        listener.bind(IpAddress("127.0.0.1", serverPort));
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            TcpClient * client = listener.accept();
            client->receive(message);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            Request * req = new Request(message.dataAsString());
            Response * res = new Response(req, Actors);
            message.setDataString(res->message());
            client->send(message);
            cout << ">> Response sent." << endl;
            delete client;
            delete req;
            delete res;
        }
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    clearActors(Actors);
    return 0;
}

vector<Actor*> createActors(void){
    vector<Actor*> Actors = {};
    Actors.push_back(new Actor(123, "Benedict Cumberbatch", "British", 1976));
    Actors.push_back(new Actor(342, "Scarlett Johansson", "American", 1983));
    Actors.push_back(new Actor(368, "Arnold Schwarzenegger", "German", 1947));
    Actors.push_back(new Actor(902, "Monica Bellucci", "Italian", 1964));
    Actors.push_back(new Actor(456, "Dwayne Johnson", "American", 1972));
    Actors.push_back(new Actor(752, "Will Smith", "American", 1968));
    Actors.push_back(new Actor(285, "Ruslan Hanumak", "Ukrainian", 1989));
    Actors.push_back(new Actor(902, "Evhenii Kosevuy", "Ukrainian", 1983));
    return Actors;
}

void clearActors(vector<Actor*> Actors){
    for(Actor *Actor : Actors) delete Actor;
}
