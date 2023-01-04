#include <bits/stdc++.h>
using namespace std;

void replace_all(
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::string buf;
    std::size_t pos = 0;
    std::size_t prevPos;

    // Reserves rough estimate of final size of string.
    buf.reserve(s.size());

    while (true) {
        prevPos = pos;
        pos = s.find(toReplace, pos);
        if (pos == std::string::npos)
            break;
        buf.append(s, prevPos, pos - prevPos);
        buf += replaceWith;
        pos += toReplace.size();
    }

    buf.append(s, prevPos, s.size() - prevPos);
    s.swap(buf);
}

int main(){
	string str1,str2,text;
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, text);
	replace_all(text, str1, str2);
	//replace_all(string, "text to replace", "new text")
	cout << text;
	return 0;
}
