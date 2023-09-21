#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <cmath>
double distancia(const std::vector<double>& point1, const std::vector<double>& point2) {
    double distance = 0.0;
    for (size_t i = 0; i < point1.size(); ++i) {
        double diff = point1[i] - point2[i];
        distance += diff * diff;
    }
    return std::sqrt(distance);
}
int main() {
    // Definir la dimensión 'd'
    int d = 5000; // DIMENSION

    //std::random_device rd;  //en caso quiera variables aleatorias cada vez que se ejecute el programa
    std::mt19937 generator(80); // reemp;azar 80 con rd
    std::uniform_real_distribution<double> distribution(0, 1);
    std::vector<std::vector<double>> points(100, std::vector<double>(d)); //PUNTOS GENERADOS
    
	std::vector<double> distances;//DISTANCIAS GENERADAS
	
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < d; ++j) {
            points[i][j] = distribution(generator);
        }
    }
    
    // Imprimir los puntos generados (solo para verificar)
    /*
    for (int i = 0; i < 100; ++i) {
        std::cout << "Punto " << i + 1 << ": ";
        for (int j = 0; j < d; ++j) {
            std::cout << points[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
	for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double distance = distancia(points[i], points[j]);
            distances.push_back(distance);
            //std::cout << "Distancia entre Punto " << i + 1 << " y Punto " << j + 1 << ": " << distance << std::endl;
        }
    }
    
    std::ofstream outputFile("distancias/distancias_"+std::to_string(d)+".txt");
    if (outputFile.is_open()) {
        for (const double& distance : distances) {
            outputFile << distance << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir las distancias." << std::endl;
        return 1; 
    }
    
    return 0;
}