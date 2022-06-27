import 'package:flutter/material.dart';

class CalculatorBMI extends StatefulWidget {
  @override
  CalculatorBMIState createState() => CalculatorBMIState();
}

class CalculatorBMIState extends State<CalculatorBMI> {
  final TextEditingController _heightController = TextEditingController();
  final TextEditingController _weightController = TextEditingController();

  double? _result;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('BMI Calculator'),
        centerTitle: true,
        backgroundColor: Colors.purpleAccent,
      ),
      body: SingleChildScrollView(
        child: Container(
          padding: EdgeInsets.symmetric(horizontal: 10.0),
          child: Column(
            children: <Widget>[
              TextField(
                controller: _heightController,
                keyboardType: TextInputType.number,
                decoration: InputDecoration(
                  labelText: 'height in cm',
                  icon: Icon(Icons.trending_up),
                ),
              ),
              SizedBox(height: 20),
              TextField(
                controller: _weightController,
                keyboardType: TextInputType.number,
                decoration: InputDecoration(
                  labelText: 'weight in kg',
                  icon: Icon(Icons.line_weight),
                ),
              ),
              SizedBox(height: 15),
              RaisedButton(
                color: Colors.purpleAccent,
                child: Text(
                  "Calculate",
                  style: TextStyle(color: Colors.white),
                ),
                onPressed: calculateBMI,
              ),
              SizedBox(height: 15),
              Text(
                _result == null ? "Result" : "${_result?.toStringAsFixed(2)}",
                style: TextStyle(
                  color: Colors.purpleAccent,
                  fontSize: 19.4,
                  fontWeight: FontWeight.w500,
                ),
              ),
              SizedBox(
                height: 10,
              ),
              Container(
                  height: 320,
                  alignment: Alignment.center,
                  child: Card(
                    child: ListView.builder(
                      itemBuilder: (ctx, i) {
                        return Column(
                          children: [
                            Container(
                              child: Card(
                                color: Color.fromARGB(255, 225, 154, 238),
                                child: Text(
                                  'A BMI of under 18.5 indicates that a person has insufficient weight, so they may need to put on some weight. They should ask a doctor or dietitian for advice.',
                                  style: TextStyle(
                                    fontSize: 20,
                                  ),
                                ),
                              ),
                            ),
                            SizedBox(
                              height: 10,
                            ),
                            Card(
                              color: Color.fromARGB(255, 225, 154, 238),
                              child: Text(
                                'A BMI of 18.5–24.9 indicates that a person has a healthy weight for their height. By maintaining a healthy weight, they can lower their risk of developing serious health problems.',
                                style: TextStyle(fontSize: 20),
                              ),
                            ),
                            SizedBox(
                              height: 10,
                            ),
                            Card(
                              color: Color.fromARGB(255, 225, 154, 238),
                              child: Text(
                                'A BMI of 25–29.9 indicates that a person is slightly overweight. A doctor may advise them to lose some weight for health reasons. They should talk with a doctor or dietitian for advice.',
                                style: TextStyle(fontSize: 20),
                              ),
                            ),
                            SizedBox(
                              height: 10,
                            ),
                            Card(
                              color: Color.fromARGB(255, 225, 154, 238),
                              child: Text(
                                'A BMI of over 30 indicates that a person has obesity. Their health may be at risk if they do not lose weight. They should talk with a doctor or dietitian for advice.',
                                style: TextStyle(fontSize: 20),
                              ),
                            ),
                          ],
                        );
                      },
                      itemCount: 1,
                    ),
                  ))
            ],
          ),
        ),
      ),
    );
  }

  void calculateBMI() {
    double height = double.parse(_heightController.text) / 100;
    double weight = double.parse(_weightController.text);

    double heightSquare = height * height;
    double result = weight / heightSquare;

    _result = result;

    setState(() {});
  }
}
