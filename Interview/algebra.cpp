#include<bits/stdc++.h>
using namespace std;
#define ll long long
string order;
int strtonum(string s){
   int p=1; 
   int ans=0;
   for(int i=s.size()-1;i>=0;i--){
       ans+= (s[i]-'0')*p; 
       p*=10;
   }
   return ans;
}
string numtostr(int n){
    string s="";
    bool sg=false;
    if(n<0){
        n*=-1;
        sg=true;
    }
    while(n>0){
        int g= n%10;
        s= char('0'+g) + s;
        n=n/10;
    }
    if(sg)
        s = '-'+s;
    return s;
}
class Term{
    public:
    int cf;
    map<char,int> vars;//x: power 
    string streqv="";


    Term(int c,map<char,int> p){
       cf = c; 
       vars = p;
    }
    Term(){

    }
    Term(string s,int sign){
        //cout<<s<<endl;
        string coe="";
        streqv = s;
        int i=0;
        for(i=0;i<s.size();i++)
            if(s[i] >='0' && s[i]<='9')
                coe+=s[i];
            else
                break;
        if(coe=="")cf=1;
        else
        cf = strtonum(coe);
        if(sign)cf=-1*cf;
        
        for(;i<s.size();i++){
           if(s[i]=='^'){
                string pow = "";
                int j;
                for(j=i+1;s[j]>='0' && s[j]<='9';j++){
                    pow+=s[j]; 
                }
                int powint = strtonum(pow);
                vars[s[i-1]] = powint;
                i = j-1;
           }
           else if(s[i]!='^' && s[i]>'9'){
            vars[s[i]] = 1;
           }
        }
    }
    Term multiply(Term T){
        int cff=1;
        map<char,int> mp(vars.begin(),vars.end()); 
        cff = cf*T.cf;
        for(auto x:T.vars){
            mp[x.first] += x.second;
        } 
        return Term(cff,mp);
    }
    string display(){
        string coe="";
        streqv="";
      if(cf==0){ 
          streqv="";
          return "";
      }
          
      if(cf!=1){
          coe = numtostr(cf);
      }
      for(auto x:order){
         if(vars[x]>0){
             streqv+=x;
             if(vars[x]>1){
             streqv+='^';
             streqv+=numtostr(vars[x]);
             }
         } 
      }
      return coe+streqv;
      
    }
};
class Expression{
    vector<Term> terms;
    public:
    Expression(string s){
        //parse
        //cout<<s<<endl;
        int es = -1;
        int neg=0;
        int i=0;
        for(i=0;i<s.size();i++){
           
           if(s[i]=='+' or s[i] == '-'){
               //cout<<s.substr(es,i-es)<<endl;
              if(es!=-1){
                  Term T(s.substr(es,i-es),neg); 
                 terms.push_back(T); 
              }
              es = -1;

              if(s[i]=='-')
                  neg=1;
              else neg=0;
          }else if(es==-1){
             es = i;
           } 
        }
        //cout<<s.substr(es,i-es)<<endl;;
       Term T(s.substr(es,i-es),neg);
       terms.push_back(T);
       //for(auto x:terms)
       //    cout<<x.display()<<" ";
       //cout<<endl;
       //cout<<"T "<<terms[0].display()<<" "<<terms[1].display()<<endl;
       Term ter = terms[0].multiply(terms[1]);
       //cout<<ter.display()<<endl;
    }
    Expression(){
        
    }
    Expression multiply(Expression e){
        Expression prod;
       map<string,int> mp; 
       int ind=0;
       for(auto t:terms){
            for(auto p:e.terms){
               Term newterm = t.multiply(p); 
               newterm.display();

              // cout<<"StrEqv "<<newterm.streqv<<" "<<mp[newterm.streqv]<<endl;
               /// cout<<"L"<<newterm.streqv<<endl;
               /// cout<<mp[newterm.streqv]<<endl;
               /// cout<<prod.terms.size()<<endl;
                if(mp[newterm.streqv]==0) 
                    mp[newterm.streqv]=0;
                int tind = mp[newterm.streqv];
                if(prod.terms.size() > 0 && prod.terms[tind].streqv == newterm.streqv)
                   prod.terms[tind].cf+= newterm.cf;
                else{
                    mp[newterm.streqv] = ind;
                    prod.terms.push_back(newterm);
                }
               
//               if(mp[newterm.streqv]==0){
//                   int tind = mp[newterm.streqv];
//                   if(prod.terms[tind].streqv == newterm.streqv)
//                      prod.terms[tind].cf+= newterm.cf;
//               }
//               else{
//                   mp[newterm.streqv]=ind;
//                   prod.terms.push_back(newterm);
//               }
               ind++;
            }
       } 
       return prod;
    }
    string display(){
        string s="";
        if(terms[0].cf<0)
            s+= terms[0].display();
        else s+= terms[0].display();
        for(int i=1;i<terms.size();i++){
            if(i<terms.size() && terms[i].cf<0)
                s+= terms[i].display();
            else if(i<terms.size() && terms[i].cf>0)
                s+= "+"+terms[i].display();
        }
        return s;
    }
    
};
vector<Expression> parse(string s){
    int es=0;
    vector<Expression> exps;
    order="";
    unordered_map<char,int> present;
    for(int i=0;i<s.size();i++)
        if(s[i]>'9' && s[i]!='^'){
            present[s[i]]++;
            if(present[s[i]]==1)
                order+=s[i];
                present[s[i]]++;
        }
    for(int i=0;i<s.size();i++)
        if(s[i]=='(')
            es=i+1;
        else if(s[i]==')'){
            exps.push_back(Expression(s.substr(es,i-es)));//bugpossible
            es=-1;
        }
    return exps;
}
Expression multiply(vector<Expression> exps){
    Expression e=exps[0];        
    //cout<<e.display()<<endl;
    for(int i=1;i<exps.size();i++)
        e = e.multiply(exps[i]);
    return e;
}
int main(){
    freopen("input.txt","r",stdin); 
    string s;
    cin>>s;
    cout<<s<<endl;
    vector<Expression> ex = parse(s);
    //Expression e= ex[0].multiply(ex[1]); 
    //cout<<e.display()<<endl;
    Expression e=multiply(ex);
    cout<<e.display()<<endl;
}
