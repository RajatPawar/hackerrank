#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> b, temp;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            cout<<"Pushing "<<s[i]<<" to stack"<<endl;
            b.push(s[i]);
        }
        else {
          char match;
          if (s[i] == '(')
            match = ')';
          else if (s[i] == '{')
            match = '}';
          else if (s[i] == '[')
            match = ']';

          cout<<"Match: "<<match;

          while(b.size()) {
              cout<<"Checking if "<<b.top()<<" = "<<match<<endl;
              if(b.top() == match) break;
              cout<<"No they aren't"<<endl;
              temp.push(b.top());
              b.pop();
          }
          if(!b.size()) return "NO";
          else {
              cout<<"That previous was a valid bracket match so pushing back"<<endl;
              while(temp.size()) {
                  b.push(temp.top());
                  temp.pop();
              }
          }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

