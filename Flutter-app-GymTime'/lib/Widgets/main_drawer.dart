import 'package:flutter/material.dart';
import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:workoutapp/models/exercise_model.dart';
import 'package:workoutapp/screens/filters_screen.dart';
import '../screens/notes_screen.dart';

class MainDrawer extends StatefulWidget {
  // const MainDrawer({Key? key}) : super(key: key);
  // final List<Exercise> favoriteMeals;
  // MainDrawer(this.favoriteMeals);
  List<Exercise> exercises = [];
  MainDrawer(this.exercises);
  @override
  State<MainDrawer> createState() => _MainDrawerState();
}

class _MainDrawerState extends State<MainDrawer> {
  Widget buildListTile(String title, IconData icon, VoidCallback tapHandler) {
    return ListTile(
      leading: Icon(
        icon,
        size: 26,
        color: Colors.deepPurpleAccent,
      ),
      title: Text(
        title,
        style: TextStyle(
          //fontFamily: 'RobotoCondensed',
          fontSize: 24,
          // fontWeight: FontWeight.bold,
        ),
      ),
      onTap: tapHandler,
    );
  }

  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: Column(
        children: <Widget>[
          Container(
            height: 120,
            width: double.infinity,
            padding: EdgeInsets.all(20),
            alignment: Alignment.centerLeft,
            color: Theme.of(context).accentColor,
            child: Text(
              'Gym Time\'',
              style: TextStyle(
                  fontWeight: FontWeight.w900,
                  fontSize: 30,
                  color: Colors.deepPurple),
            ),
          ),
          SizedBox(
            height: 20,
          ),
          buildListTile('Training categories', Icons.balcony, () {
            Navigator.of(context).pushReplacementNamed('/');
          }),
          buildListTile('Filters', Icons.settings, () {
            Navigator.of(context).pushReplacementNamed(FiltersScreen.routeName);
          }),
          buildListTile('Notes', Icons.note, () {
            Navigator.of(context).pushReplacementNamed('/notes');
          }),
          buildListTile('Help', Icons.help, () {
            Navigator.of(context).pushReplacementNamed('/help');
            // Navigator.of(context).pushReplacementNamed(FiltersScreen.routeName);
          }),
        ],
      ),
    );
  }
}
