#ifndef _VOICE_H
#define _VOICE_H

#include <iostream>

using namespace std;

class Voice {
public:
    void say(string phrase);
};

#endif




#ifndef _bot_H
#define _bot_H

#include <iostream>
#include <fstream>

using namespace std;

class bot {
public:
    void respond(string phrase);
    void say(string phrase);

    Voice voice;
};

#endif




#include <iostream>
#include <fstream>

using namespace std;

void bot::respond(string phrase){
    fstream memory;
    memory.open("memory/memory.txt", ios::in);

    while( !memory.eof() ){    // While not at end of file
        string identifier;
        getline(memory,identifier);    // Get next phrase

        if(identifier == phrase){    // Is it the phrase we are looking for
            string response;
            getline(memory,response);   // If so, get the response
            voice.say(response);   // Textually and audibly output the response!
            return;
        }
    }

    memory.close();    // Looks like we couldn't find the phrase in memory. Close the file!
    memory.open("memory/memory.txt", ios::out | ios::app);    // Now open for output, and append at end of file
    memory << phrase << endl;    // Record initial phrase in memory

    voice.say(phrase);   // Repeat the phrase the user entered
    string userResponse;
    cout << "YOU: ";
    getline(cin, userResponse);    // Get the ideal response
    memory << userResponse << endl;    // Write the ideal response to memory
    memory.close();    // Close the file!
}

/*
    This function simply communicates a phrase textually and audibly
*/
void bot::say(string phrase){
    this->voice.say(phrase);
}


#include <iostream>
#include <windows.h>

using namespace std;


void Voice::say(string phrase){
    string command = "espeak \"" + phrase + "\"";    // Concat
    const char* charCommand = command.c_str();
    cout << phrase << endl;
    system(charCommand);
}




#include <iostream>

using namespace std;

main(){
    bot AI;
    for(;;){
        cout << "\nYOU: ";
        string phrase;
        getline(cin, phrase);
        cout << "COMPUTER: ";
        AI.respond(phrase);
    }
}

