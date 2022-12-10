#ifndef APLLICATION_H
#define APLLICATION_H

#define BASE_APP_MAIN(App)          \
int main(int argc, char* argv[])    \
{                                   \
    App* pApp = new App;            \
    try                             \
    {                               \
        pApp->main(argc, argv);     \
    }                               \
    catch(...)                      \
    {                               \
        delete pApp;                \
        return 1;                   \
    }                               \
    delete pApp;                    \
}
#endif
