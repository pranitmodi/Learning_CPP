string str = s.substr(0,i);
                    cout << "First Part: " << str << endl;
                    str.append(s.substr(i+t,l-i-t));
                    cout << "Second Part: " <<  str << endl;
                    s = str;
                    counter = 1;
                    break;