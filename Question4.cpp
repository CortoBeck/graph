#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>


// Classe pour les graphes avec des sommets de type int
class GraphInt {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
    std::unordered_map<int, bool> visite;

public:
   
    
     void addsommet(int s) {
        // Ajout d'un sommet, s'il n'existe pas déjà
        if (adj.find(s) == adj.end()) { //Documentation de unorderedmap
            adj[s] = {};  
            visite[s] = false;
        }
    }
    

    //Ajouter une arête entre deux sommets déjà existants
    void addarete(int origine, int arrivee, int poids) {
        adj[origine].push_back({arrivee, poids});
    }

    //Ajouter deux sommets et une arête entre ces sommets
    void addEdge(int origine, int arrivee, int poids) {
        addsommet(origine);
        addsommet(arrivee);
        addarete(origine, arrivee, poids);
    }

    void AfficherSommet(int s) const {
        std::cout << s;
    }

      void Affichergraph() const {
        std::cout << "{";
        bool second = true;
        for (const auto& paire : adj) {
            if (!second){
                std::cout << ", ";
            }
            
            AfficherSommet(paire.first);
            std::cout << ": [";
            bool first = true;
            for (const auto& arete : paire.second) {
                if (!first) {
                    std::cout << ", ";
                }
                AfficherSommet(arete.first);
                std::cout << "(" << arete.second << ")"; 
                first = false;
            }
            std::cout << "]" ;
            second = false;

        }
        std::cout << "}" << std::endl;
    }

    void dfs(int sommet) {
        if (visite[sommet]) return;  // Si déjà visité, on arrête
        std::stack <int> pile;
        pile.push(sommet);
        while(!pile.empty()){
            int n = pile.top();
            pile.pop();
        
            if (!visite[n]) {
                visite[n] = true;
                std::cout << "Visité: ";
                AfficherSommet(n);
                std::cout << std::endl;
            }

            for (const auto& arete : adj[n]) {
                if (!visite[arete.first]) {
                    pile.push(arete.first);
                }
            }
        }
        }
        
    void bfs(int sommet) {
        if (visite[sommet]) return;  // Si déjà visité, on arrête
        std::queue <int> file;
        file.push(sommet);
        while(!file.empty()){
            int n = file.front();
            file.pop();
        
            if (!visite[n]) {
                visite[n] = true;
                std::cout << "Visité: ";
                AfficherSommet(n);
                std::cout << std::endl;
            }

            for (const auto& arete : adj[n]) {
                if (!visite[arete.first]) {
                    file.push(arete.first);
                }
            }
        }
        }
    
};

// Classe pour les graphes avec des sommets de type string
class GraphString {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;
    std::unordered_map<std::string, bool> visite;

public:
    void addsommet(const std::string& s) {
        if (adj.find(s) == adj.end()) {
            adj[s] = {};
            visite[s] = false;
        }
    }

    void addarete(const std::string& origine, const std::string& arrivee, int poids) {
        adj[origine].push_back({arrivee, poids});
    }

    void addEdge(const std::string& origine, const std::string& arrivee, int poids) {
        addsommet(origine);
        addsommet(arrivee);
        addarete(origine, arrivee, poids);
    }

    void AfficherSommet(const std::string& sommet) const {
        std::cout << sommet;
    }

      void Affichergraph() const {
        std::cout << "{";
        bool second = true;
        for (const auto& paire : adj) {
            if (!second){
                std::cout << ", ";
            }
            
            AfficherSommet(paire.first);
            std::cout << ": [";
            bool first = true;
            for (const auto& arete : paire.second) {
                if (!first) {
                    std::cout << ", ";
                }
                AfficherSommet(arete.first);
                std::cout << "(" << arete.second << ")"; 
                first = false;
            }
            std::cout << "]" ;
            second = false;

        }
        std::cout << "}" << std::endl;
    }
    
    void dfs(const std::string& sommet) {
        if (visite[sommet]) return;  // Si déjà visité : on arrête
        std::stack<std::string> pile;
        pile.push(sommet);
        while(!pile.empty()){
            std::string n = pile.top();
            pile.pop();
        
            if (!visite[n]) {
                visite[n] = true;
                std::cout << "Visité: ";
                AfficherSommet(n);
                std::cout << std::endl;
            }

            for (const auto& arete : adj[n]) {
                if (!visite[arete.first]) {
                    pile.push(arete.first);
                }
            }
        }
        }
    
    void bfs(const std::string& sommet) {
        if (visite[sommet]) return;  // Si déjà visité : on arrête
        std::queue<std::string> file;
        file.push(sommet);
        while(!file.empty()){
            std::string n = file.front();
            file.pop();
        
            if (!visite[n]) {
                visite[n] = true;
                std::cout << "Visité: ";
                AfficherSommet(n);
                std::cout << std::endl;
            }

            for (const auto& arete : adj[n]) {
                if (!visite[arete.first]) {
                    file.push(arete.first);
                }
            }
        }
        }

};

int main() {
    // Utilisation du graphe avec des sommets de type int
    GraphInt gInt;
    gInt.addEdge(1, 2, 10);
    gInt.addEdge(1, 3, 20);
    gInt.addEdge(2, 3, 30);
    gInt.addEdge(3, 4, 40);

    std::cout << "Graph avec des sommets de type int:" << std::endl;
    gInt.Affichergraph();

    std::cout << "Parcours en largeur depuis le sommet 1:" << std::endl;
    gInt.bfs(1);

    // Utilisation du graphe avec des sommets de type string
    GraphString gString;
    gString.addEdge("Paris", "Lyon", 100);
    gString.addEdge("Paris", "Marseille", 150);
    gString.addEdge("Lyon", "Nice", 80);
    gString.addEdge("Marseille", "Nice", 70);
    gString.addEdge("Nice", "Paris", 200);

    std::cout << "Graph avec des sommets de type string:" << std::endl;
    gString.Affichergraph();

    std::cout << "Parcours en largeur depuis 'Paris':" << std::endl;
    gString.bfs("Paris");

    return 0;
}