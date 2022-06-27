import 'package:flutter/material.dart';
import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:workoutapp/Widgets/main_drawer.dart';
import 'package:workoutapp/models/exercise_model.dart';

class Help extends StatelessWidget {
  //const Help({Key? key}) : super(key: key);
  static const routName = '/help';
  List<Exercise> exercises = [];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Help'),
      ),
      drawer: MainDrawer(exercises),
      body: Container(
          width: double.infinity,
          child: Column(
            children: [
              SizedBox(
                height: 10,
              ),
              Text(
                'App info and help',
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 20),
              ),
              SizedBox(
                height: 10,
              ),
              Card(
                elevation: 7,
                child: Container(
                  width: double.infinity,
                  child: Icon(
                    Icons.live_help,
                    size: 150,
                  ),
                  height: 620,
                ),
              )
            ],
          )),
    );
  }
}
