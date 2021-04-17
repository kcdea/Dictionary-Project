// #include <iomanip>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <fstream>
// #include <string>

// class dictionaryTree{
    
//     /*
//     Each Node contains a character and its 26 children, one for each character a to z.
//     In addition, the Node has a pointer back to its parent. 
//     */

//     struct Node
//     {
//         char letter;
//         Node* parent;
//         std::vector<Node*> children;
//     };

//     /* Class variables:
//             root: Root of the tree which will be a null character
//             numLevels: Height of the tree 
//     */

//     Node* root;             
//     int numLevels;       


//     /*
//     i. Initializes the 26 children of a given node
//     ii. Some characters do not appear after a certain character in the dictionary, e.g. 'q','v', and 'x' do not appear after 'g'
//     This function takes care of this scenerio. For the character, call it 'c', in a given node, call it 'n', 
//     the characters that do not follow 'c', are set to '\0' in the children of 'n'.
//     */

//     void childrenInit(Node* node){

//         /* i. initalize the node's children, i.e. a child for each character from a to z */
//         root=new Node();
//         for (int i=97; i<123; i++)
//         {
//             Node* temp = new Node();
//             temp->letter=i;
//             temp->parent=node;
//             node->children.push_back(temp);
//         }

//         /* performs ii. */
//         if (node->letter =='b')
//         {
//             node->children[16]->letter='\0';
//             node->children[23]->letter='\0';
//         }
//         if (node->letter == 'c')
//         {
//             node->children[9]->letter= '\0';
//             node->children[23]->letter= '\0';
//         }
//         if (node->letter == 'd') node->children[23]->letter='\0';
//         if (node->letter == 'f')
//         {
//             node->children[16]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[23]->letter='\0';
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'g')
//         {
//             node->children[16]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[23]->letter='\0';
//         }
//         if (node->letter == 'h')
//         {
//             node->children[23]->letter='\0';
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'j')
//         {
//             node->children[1]->letter='\0';
//             node->children[2]->letter='\0';
//             node->children[3]->letter='\0';
//             node->children[5]->letter='\0';
//             node->children[6]->letter='\0';
//             node->children[7]->letter='\0';
//             node->children[9]->letter='\0';
//             node->children[10]->letter='\0';
//             node->children[11]->letter='\0';
//             node->children[12]->letter='\0';
//             node->children[13]->letter='\0';
//             node->children[16]->letter='\0';
//             node->children[18]->letter='\0';
//             node->children[19]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[22]->letter='\0';
//             node->children[23]->letter='\0';
//             node->children[24]->letter='\0';
//             node->children[25]->letter='\0';
//         }
       
//         if (node->letter == 'k')
//         {
//             node->children[16]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[23]->letter='\0';
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'l')
//         {
//             node->children[23]->letter='\0';
//         }
//         if (node->letter == 'm')
//         {
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'p')
//         {
//             node->children[16]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[23]->letter='\0';
//         }
        
     
//         if (node->letter == 'q')
//         {
//             node->children[1]->letter='\0';
//             node->children[5]->letter='\0';
//             node->children[6]->letter='\0';
//             node->children[7]->letter='\0';
//             node->children[9]->letter='\0';
//             node->children[10]->letter='\0';
//             node->children[13]->letter='\0';
//             node->children[16]->letter='\0';
//             node->children[18]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[22]->letter='\0';
//             node->children[23]->letter='\0';
//             node->children[24]->letter='\0';
//             node->children[25]->letter='\0';
//         }
        
//         if (node->letter == 's')
//         {
//             node->children[23]->letter='\0';
//         }
//         if (node->letter == 't')
//         {
//             node->children[16]->letter='\0';
//         }
    
//         if (node->letter == 'v')
//         {
//             node->children[1]->letter='\0';
//             node->children[5]->letter='\0';
//             node->children[6]->letter='\0';
//             node->children[7]->letter='\0';
//             node->children[9]->letter='\0';
//             node->children[10]->letter='\0';
//             node->children[12]->letter='\0';
//             node->children[15]->letter='\0';
//             node->children[16]->letter='\0';
//             node->children[19]->letter='\0';
//             node->children[22]->letter='\0';
//             node->children[23]->letter='\0';
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'w')
//         {
//             node->children[9]->letter='\0';
//             node->children[21]->letter='\0';
//             node->children[23]->letter='\0';
//         }
//         if (node->letter == 'x')
//         {
//             node->children[3]->letter='\0';
//             node->children[9]->letter='\0';
//             node->children[10]->letter='\0';
//             node->children[17]->letter='\0';
//             node->children[25]->letter='\0';
//         }
//         if (node->letter == 'y')
//         {
//             node->children[16]->letter='\0';
//             node->children[24]->letter='\0';
//         }
//         if (node->letter == 'z')
//         {
//             node->children[2]->letter='\0';
//             node->children[5]->letter='\0';
//             node->children[9]->letter='\0';
//             node->children[13]->letter='\0';
//             node->children[16]->letter='\0';
//             node->children[23]->letter='\0';
//         }

//     }       


// public:
//     dictionaryTree()
//     {   
//         numLevels=22;                                   //longest word in the data has length 21
//         root = new Node();                                  
//         root->letter='\0';                              //initializing the root and its 26 children, for a to z 
//         root->parent=nullptr;
//         for (int i=97; i<123; i++){
//             Node* node = new Node();
//             node->letter=i;
//             node->parent=root;
//             root->children.push_back(node);
//         }

//         std::queue<std::vector<Node*>> Q;               //queue to expand the tree level by level
//         Q.push(root->children);

//         for (int i=0; i<numLevels; i++)
//         {
//             int levelSize = Q.size();
//             for (int j=0; j<levelSize; j++)
//             {
//                 std::vector<Node*> _children = Q.front();
//                 for (auto child:_children)
//                 {
//                     childrenInit(child);
//                     Q.push(child->children); 
//                 }
//                 Q.pop();
//             }
//         }

//     }

    

//     /* 
//     Traverses the tree based on the given word.
//     If along the path, finds a '\0', it means the word does not appear in the dicttionary.
//     */

//     bool found(std::string word){
//         Node* key = root;
//         for (auto c:word)
//         {
//             if (!key->children.empty() && key->children[c]->letter!='\0') key = key->children[c];
//             else if (!key->children.empty() && key->children[c]->letter=='\0') return false;
//         }
//         return true;
//     }
// };


// int main(){
//     dictionaryTree dict;
//     std::string word = "hello";
//     std::ifstream file("engmix.txt");
//     int longest=0;
//     int current=0;
//     int count=0;
//     std::string lWord;
//     while(!file.eof())
//     {
//         std::string line;
//         getline(file, line);
//         if (dict.found(line)) count++;
//         // current=line.size();
//         // if (current>longest) {
//         //     lWord=line;
//         //     longest=current;
//         // }
//     }
//     std::cout << "the number of words in the file: " << count << std::endl;
//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;
class dictionaryHashTable{
    unordered_set<string> words;
public:
    dictionaryHashTable(ifstream &file)
    {
        while(!file.eof())
        {
            string word;
            getline(file, word);
            words.insert(word);
        }
    }
    unordered_set<string> getWords()
    {
        return words;
    }
    bool found(string &word)
    {
        if (words.count(word)) return true;
        else return false;
    }
   
};

int main()
{
    ifstream file("engmix.txt");
    dictionaryHashTable dictionary(file);
    unordered_set<string> words = dictionary.getWords();
    for (auto & word:words)
        cout << word << endl;
    return 0;
}