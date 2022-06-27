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

      avaliableExercises = listOfExercises.where((ex) {
        if (_filters['forBeginners'] as bool && !ex.isForBeginners) {
          return false;
        }
        if (_filters['easy'] as bool && !ex.isEasy) {
          return false;
        }
        if (_filters['advanced'] as bool && !ex.isAdvanced) {
          return false;
        }
        if (_filters['hard'] as bool && !ex.isHard) {
          return false;
        }
        return true;
      }).toList();
    });
  }

  //const MyApp({Key? key}) : super(key: key);
  List<Exercise> _favoriteEx = [];

  void _toggleFavorite(String exId) {
    final existingIndex = _favoriteEx.indexWhere((ex) => ex.id == exId);
    if (existingIndex >= 0) {
      setState(() {
        _favoriteEx.removeAt(existingIndex);
      });
    } else {
      setState(() {
        _favoriteEx.add(
          listOfExercises.firstWhere((ex) => ex.id == exId),
        );
      });
    }
  }

  bool _isFavorite(String id) {
    return _favoriteEx.any((ex) => ex.id == id);
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
        '/': (ctx) => TabsScreen(_favoriteEx),
        '/category-ex': (ctx) => CategoryExercisesScreen(avaliableExercises),
        '/detail': (ctx) => ExDetailScreen(_toggleFavorite, _isFavorite),
        '/favorites': (ctx) => FavoritesScreen(_favoriteEx),
        FiltersScreen.routeName: (ctx) => FiltersScreen(_filters, _setFilters),
        '/notes': (ctx) => NotesScreen(),
        //NoteDetail.routeName: (ctx) => NoteDetail(),
        //'/test': (ctx) => Test(),
        '/help': (ctx) => Help(),
      },
    );
  }
}
