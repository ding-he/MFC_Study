#ifdef DLL1_API
#else
#define DLL1_API extern "C" _declspec(dllimport)
#endif // DLL1_API


DLL1_API int /*_stdcall*/ add(int x, int y);
DLL1_API int /*_stdcall*/ subtract(int x, int y);

/*class DLL1_API Point
{
public:
	void output(int x, int y);
};*/