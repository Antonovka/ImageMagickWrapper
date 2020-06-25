#include "consoleprocessing.h"

using namespace std;

ConsoleProcessing::ConsoleProcessing()
{
    // load
    auto load = [&]()
    {
        string name, filename;

        cin >> name >> filename;

        string result = imgProc.load(name, filename);
        if (result.size() > 0)
            cout << result << endl;

        return true;
    };
    operations["load"]  = load;
    operations["ld"]    = load;

    // store
    auto store = [&]()
    {
        string name, filename;

        cin >> name >> filename;

        string result = imgProc.write(name, filename);
        if (result.size() > 0)
            cout << result << endl;

        return true;
    };
    operations["store"] = store;
    operations["s"]     = store;


    // blur
    auto blur = [&]()
    {
        string fromName, toName, radius;

        cin >> fromName >> toName >> radius;

        string result = imgProc.blur(fromName, toName, radius);
        if (result.size() > 0)
            cout << result << endl;

        return true;
    };
    operations["blur"] = blur;

    // resize
    auto resize = [&]()
    {
        string fromName, toName, newWidth, newHeight;

        cin >> fromName >> toName >> newWidth >> newHeight;

        string result = imgProc.zoom(fromName, toName, newWidth, newHeight) ;
        if (result.size() > 0)
            cout << result << endl;

        return true;
    };
    operations["resize"] = resize;

    // help
    auto help = []()
    {
        cout << "Usage: Command [Argument]...\n";
        cout << "Image processing application\n\n";
        cout << " load, ld  <name> <filename>                               Uploading image\n";
        cout << " store, s  <name> <filename>                               Saving image\n";
        cout << " blur      <from_name> <to_name> <size>                    Smoothing image\n";
        cout << " resize    <from_name> <to_name> <new_width> <new_height>  Resize image\n";
        cout << " help, h                                                   Help\n";
        cout << " exit, quit, q                                             Exit";
        cout << endl;

        return true;
    };
    operations["help"] = help;
    operations["h"] = help;

    // exit
    auto exit = []()
    {
        return false;
    };

    operations["exit"]  = exit;
    operations["quit"]  = exit;
    operations["q"]     = exit;
}

void ConsoleProcessing::run()
{
    while (true)
    {
        string command;

        cin >> command;

        if (!processing(command))
        {
            break;
        }
    }
}

bool ConsoleProcessing::processing(string command)
{
    if (operations.find(command) == operations.end())
    {
        cout << "Invalid command" << endl;

        std::string buffer;
        getline(cin, buffer);

        return true;
    }

    return operations[command]();
}
