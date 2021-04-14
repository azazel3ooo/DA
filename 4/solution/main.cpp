#include <iostream>
#include <vector>

long long min(long long a, long long b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

std::vector<long long> z_function(const std::vector<char> s, long long s_size){
    std::vector<long long> z(s_size, 0);
    long long l = 0;
    long long r = 0;
    for (long long i = 1; i < s_size; ++i){
        if (i <= r){
            z[i] = min(r + 1 - i, z[i - l]);
        }
        while (z[i] + i < s_size && s[z[i]] == s[z[i] + i]){
            z[i]++;
        }
        if (z[i] - 1 + i > r){
            l = i;
            r = z[i] - 1 + i;
        }
    }
    return z;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::vector<char> v;
    std::vector<char> v_without_new_line;
    int c, pre_c;
    bool end_pattern = true;
    long long count = 0;
    while ((c = getchar()) != EOF){//read pattern$text
        c = (unsigned char)tolower(c);
        if (c == ' '){
            c = '|';
        } else if (c == '\n' && end_pattern){
            c = '$';
            end_pattern = false;
        } else if (c == '\n' && !end_pattern){
            c = '/';
            v.push_back(c);
            c = '|';
            v_without_new_line.push_back(c);
            pre_c = c;
            continue;
        }
        if ((pre_c == c && c == '|') || (pre_c == '$' && c == '|')){
            continue;
        }
        pre_c = c;
        v_without_new_line.push_back(c);
        v.push_back(c);
    }
    std::vector<char> n_v;
    pre_c = -1;
    bool flag = true;
    for (char i : v_without_new_line){
        if (pre_c == i && i == '|')
            continue;
        if (i == '$')
            flag = false;
        if (flag)
            count++;
        n_v.push_back(i);
        pre_c = i;
    }
    std::vector<long long> z_res = z_function(n_v, n_v.size());
    long long line = 1;
    long long word = 1;
    for (long long i = count, j = count; i < v.size(); ++i){
//        std::cout << z_res[j] << ':' << n_v[j] << ':' << v[i] << ' ';
        if (v[i] != n_v[j]){
            if (v[i] == '|'){
                word++;
                continue;
            } else if (v[i] == '/'){
                line++;
                word = 1;
                if (i + 1 < v.size())
                	if (v[i + 1] != '|' && v[i + 1] != '/' && n_v[j] == '|')
                    	j++;
                continue;
            }
        }
        if (v[i] == '|'){
            word++;
            j++;
            continue;
        } else if (v[i] == '/'){
            line++;
            word = 1;
            j++;
            continue;
        }
        if (z_res[j] == count){
            std::cout << line << ',' << ' ' << word << std::endl;
        }
        j++;
    }

    return 0;
}
