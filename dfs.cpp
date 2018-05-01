#include <iostream>
#include <vector>

int n = 3;
std::vector<std::pair<std::vector<int>,std::vector<int>>> visited;

std::ostream& operator<<(std::ostream &out, std::vector<int> vector) {
    for( auto elem : vector ) {
        out << elem << " ";// << std::endl;
    }
    return out;
}

bool VisitedNode(std::vector<int> v,std::vector<int> w) {
    std::cout << "[ INFO ]:::VisitedNode" << std::endl;
    std::pair<std::vector<int>,std::vector<int>> node (v, w);
    for (auto elem : visited){
      //std::cout << "[ INFO ]:::VisitedNode::node.first: " << node.first << "pair.second: " << node.second << std::endl;
      //std::cout << "[ INFO ]:::VisitedNode::elem.first: " << elem.first << "elem.second: " << elem.second << std::endl;
        if (node.first == elem.first && node.second == elem.second) {
            std::cout << "[ INFO ]:::VisitedNode::return true"  << std::endl;
            return true;
        }
    }
    std::cout << "[ INFO ]:::VisitedNode::return false"  << std::endl;
    visited.push_back(node);
    return false;
}

void DFS( std::vector<int> v, std::vector<int> w){
    std::cout << "[ INFO ]:::DFS" << std::endl;
    std::cout << "[ INFO ]:::DFS:: v: " << v << ", w: " << w << std::endl;

    if (VisitedNode(v,w) == true)
        return;
    if( v.empty()) {
        std::cout << "[ INFO ]:::DFS::v is empty " << std::endl;
        std::cout << "===========================" << std::endl;
        return;
    }

    for (const auto &elem : v) {
        std::vector<int> vP = v;
        std::vector<int> wP = w;
        std::vector<int>::iterator it = vP.begin();
        std::cout << "[ INFO ]:::DFS::Iterator it: " << *it << std::endl;
        wP.push_back(elem);
        vP.erase(it);
        std::cout << "[ INFO ]:::DFS::Elem value: " << elem << std::endl;
        std::cout << "[ INFO ]:::DFS::Variable send to DFS: vP: " << vP << " i wP: " << wP << std::endl;
        DFS(vP, wP);
    }
}


int main() {
    std::cout << "[ INFO ]:::Main" << std::endl;

    std::vector< int > permutacja, parents;
    for(int i = 1; i <= n; ++i){
        permutacja.push_back(i);
    }

    DFS(permutacja, parents);
}
