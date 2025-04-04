#include <iostream>
#include <fstream>

using namespace std;

double** readRatings();

void calculateMovieAverages(double** ratings, int movieId);

void calculateUserAverages(double** ratings, int user);

int main(){
  string selection;
  int number;

  double** ratings = readRatings();   
  
  while(true){
    cin >> selection;
    if (selection == "quit"){
      break;
    }
    cin >> number;
    if(selection == "movie"){
      calculateMovieAverages(ratings, number);
    } else if (selection == "user"){
      calculateUserAverages(ratings, number);
    }
  }

  for (int i = 0; i < 610; i++) {
    delete[] ratings[i];
  }
  delete[] ratings;
  return 0;
}

double** readRatings(){
  ifstream fin("ratings.tsv");
  
  double** ratings = new double*[610]; 
  for (int i = 0; i < 610; i++) {
    ratings[i] = new double[9724]; 
    for (int j = 0; j < 9724; j++) {
      ratings[i][j] = 0.0; 
    }
  }

  string junk;
  fin >> junk >> junk >> junk;

  int userId, movieId;
  double rating;
  while (fin >> userId >> movieId >> rating) {
    ratings[userId][movieId] = rating;
  }

  return ratings;
}

void calculateMovieAverages(double** ratings, int movieId) {
  double sum = 0.0;
  int count = 0;
  for (int i = 0; i < 610; i++) {
    if (ratings[i][movieId] != 0.0) {
    sum += ratings[i][movieId];
    count++;
    }
  }
  double average = sum / count;
  cout << average << endl;
}

void calculateUserAverages(double** ratings, int user) {
  double sum = 0.0;
  int count = 0;
  for (int j = 0; j < 9724; j++) {
    if (ratings[user][j] != 0.0) {
    sum += ratings[user][j];
    count++;
    }
  }  
  double average = sum / count;
  cout << average << endl;
}

