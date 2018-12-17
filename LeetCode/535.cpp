#include<bits/stdc++.h>
using namespace std;

string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 121;
    unordered_map<string,string> m;  //key is longURL, value is shortURL
    unordered_map<int,string> idm;  //key is id in DB, value is longURL
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(m.find(longUrl) != m.end())return m[longUrl];
        string res = "";
        id++;
        int count = id;
        cout << "count = " << count << endl;
        while(count > 0)
        {
        	cout << "count % 62 = " << (count%62) << endl;
            res = dict[count%62] + res;
            cout << "res = " << res << endl;
            count /= 62;
        }
        while(res.size() < 6)
        {
            res = "0" + res;
        }
        m[longUrl] = res;
        idm[id] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = 0;
        for(int i = 0; i < shortUrl.size(); i++)
        {
            id = 62*id + (int)(dict.find(shortUrl[i]));
            cout << "id = " << id << endl;
        }
        //cout << id << endl;
        if(idm.find(id) != idm.end())return idm[id];
        return "";
    }


int main() {
	
	string lurl = "http://www.vinit.com";
	string enc = encode(lurl);
	cout << "encoded = " << enc << endl;
	string dec = decode(enc);
	cout << "decoded = " << dec << endl;
	
	return 0;
}
