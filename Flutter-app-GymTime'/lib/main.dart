import 'package:flutter/material.dart';
import 'package:workoutapp/Widgets/new_note.dart';
//import 'package:workoutapp/Widgets/note_detail.dart';
//import 'package:workoutapp/Widgets/test.dart';
import 'package:workoutapp/data.dart';
import 'package:workoutapp/models/exercise_model.dart';
import 'package:workoutapp/models/note_model.dart';
import 'package:workoutapp/screens/exercise_detail_screen.dart';
import 'package:workoutapp/screens/exercises_screen.dart';
import 'package:workoutapp/screens/favorites.dart';
import 'package:workoutapp/screens/help.dart';
import 'package:workoutapp/screens/notes_screen.dart';
import 'package:workoutapp/screens/personal_screen.dart';
import 'package:workoutapp/screens/tabs_screen.dart';
import './screens/categories_execises.dart';
import './screens/filters_screen.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  Map<String, bool> _filters = {
    'forBeginners': false,
    'easy': false,
    'advanced': false,
    'hard': false,
  };
  List<Exercise> avaliableExercises = listOfExercises;

  void _setFilters(Map<String, bool> filterData) {
    setState(() {
      _filters = filterData;

      avaliableExercises = listOfExercises.where((meal) {
        if (_filters['forBeginners'] as bool && !meal.isForBeginners) {
          return false;
        }
        if (_filters['easy'] as bool && !meal.isEasy) {
          return false;
        }
        if (_filters['advanced'] as bool && !meal.isAdvanced) {
          return false;
        }
        if (_filters['hard'] as bool && !meal.isHard) {
          return false;
        }
        return true;
      }).toList();
    });
  }

  //const MyApp({Key? key}) : super(key: key);
  List<Exercise> _favoriteMeals = [];

  void _toggleFavorite(String mealId) {
    final existingIndex =
        _favoriteMeals.indexWhere((meal) => meal.id == mealId);
    if (existingIndex >= 0) {
      setState(() {
        _favoriteMeals.removeAt(existingIndex);
      });
    } else {
      setState(() {
        _favoriteMeals.add(
          listOfExercises.firstWhere((meal) => meal.id == mealId),
        );
      });
    }
  }

  bool _isMealFavorite(String id) {
    return _favoriteMeals.any((meal) => meal.id == id);
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Gym-Time',
      theme: ThemeData(
        primarySwatch: Colors.deepPurple,
        primaryColor: Colors.deepPurple,
        accentColor: Colors.deepPurpleAccent,
        hintColor: Colors.deepPurple,
      ),
      initialRoute: '/',
      routes: {
        '/': (ctx) => TabsScreen(_favoriteMeals),
        '/category-ex': (ctx) => CategoryExercisesScreen(avaliableExercises),
        '/detail': (ctx) => ExDetailScreen(_toggleFavorite, _isMealFavorite),
        '/favorites': (ctx) => FavoritesScreen(_favoriteMeals),
        FiltersScreen.routeName: (ctx) => FiltersScreen(_filters, _setFilters),
        '/notes': (ctx) => NotesScreen(),
        //NoteDetail.routeName: (ctx) => NoteDetail(),
        //'/test': (ctx) => Test(),
        '/help': (ctx) => Help(),
      },
    );
  }
}
