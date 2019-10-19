class Car {
  final String color;
  final String model;
  
  Car({this.color, this.model});
  
  // TODO: print method
}


main() {
  Car nissan = Car(color: 'Red', model: 'Nissan 92A');
  Car honda = Car(color: 'blue', model: ' Honda X-200');

   print('my car is ${nissan.color} and model ${nissan.model}');
  print('my car is ${honda.color} and model ${honda.model}');
}
