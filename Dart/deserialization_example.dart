class Product {
 final String name;
 final String type;
  
 Product({this.name, this.type});
  
  factory Product.fromMap(Map<String, String> data){
    return Product(
      name: data['name'],
      type: data['type'],
    );
  }
}


main() {
  Map<String, String> my_data = {'name': 'Adidas', 'type': 'shoes'};
  
  var deserialized_product = Product.fromMap(my_data);
  
  print('You bought ${deserialized_product.name} ${deserialized_product.type}');
  
}
