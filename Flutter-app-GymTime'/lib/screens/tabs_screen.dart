import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:flutter/material.dart';
import 'package:workoutapp/Widgets/main_drawer.dart';
import 'package:workoutapp/models/exercise_model.dart';
import 'package:workoutapp/screens/exercises_screen.dart';
import 'package:workoutapp/screens/favorites.dart';
import 'package:workoutapp/screens/personal_screen.dart';
import 'package:workoutapp/screens/training_screen.dart';

class TabsScreen extends StatefulWidget {
  // const TabsScreen({Key? key}) : super(key: key);
  final List<Exercise> favoriteMeals;

  TabsScreen(this.favoriteMeals);

  @override
  State<TabsScreen> createState() => TabsScreenState();
}

class TabsScreenState extends State<TabsScreen> {
  List<Map<String, Object>>? tabs;

  int selectedPageIndex = 0;

  void initState() {
    tabs = [
      {
        'page': TrainingScreen(),
        'title': 'Training',
      },
      {
        'page': ExercisesScreen(),
        'title': 'Exercises',
      },
      {
        'page': FavoritesScreen(widget.favoriteMeals),
        'title': 'Favorite exercises',
      },
      {
        'page': CalculatorBMI(),
        'title': '',
      },
    ];
    super.initState();
  }

  void selectPage(int index) {
    setState(() {
      selectedPageIndex = index;
    });
  }

  List<Exercise> exercises = [];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(tabs![selectedPageIndex]['title'] as String),
      ),
      body: tabs![selectedPageIndex]['page'] as Widget,
      drawer: MainDrawer(exercises),
      bottomNavigationBar: BottomNavigationBar(
        selectedLabelStyle: TextStyle(color: Colors.deepPurple),
        unselectedLabelStyle: TextStyle(color: Colors.deepPurple),
        //fixedColor: Colors.deepPurple,
        onTap: selectPage,
        currentIndex: selectedPageIndex,
        selectedItemColor: Color.fromARGB(255, 245, 240, 246),
        backgroundColor: Colors.white,

        unselectedItemColor: Color.fromARGB(255, 187, 171, 231),
        items: [
          BottomNavigationBarItem(
              icon: Icon(Icons.sports),
              // activeIcon: Icon(Icons.sports_gymnastics),
              label: 'Training',
              backgroundColor: Theme.of(context).primaryColor),
          BottomNavigationBarItem(
              icon: Icon(Icons.sports_gymnastics),
              label: 'Exercises',
              backgroundColor: Theme.of(context).primaryColor),
          BottomNavigationBarItem(
              icon: Icon(Icons.star),
              label: 'My favorutes',
              backgroundColor: Theme.of(context).primaryColor),
          BottomNavigationBarItem(
              icon: Icon(Icons.calculate),
              label: 'BMI calculator',
              backgroundColor: Theme.of(context).primaryColor),
        ],
      ),
    );
  }
}
