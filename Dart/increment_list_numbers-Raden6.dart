main() {
    List<int> my_numbers = [1, 2, 3, 4, 5];
    List<int> added_numbers = [];
  
  for(int i=0; i<my_numbers.length; i++){
    added_numbers.add(my_numbers[i] + 1);
    print(added_numbers[i]);
  }
}
