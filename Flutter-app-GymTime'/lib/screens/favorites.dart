import 'package:flutter/material.dart';
import 'package:workoutapp/Widgets/exercise_item.dart';
import 'package:workoutapp/models/exercise_model.dart';

class FavoritesScreen extends StatelessWidget {
  final List<Exercise> favoriteMeals;

  FavoritesScreen(this.favoriteMeals);

  @override
  Widget build(BuildContext context) {
    if (favoriteMeals.isEmpty) {
      return Scaffold(
        body: Center(
          child: Text('You have no favorites yet!'),
        ),
      );
    } else {
      return ListView.builder(
        itemBuilder: (ctx, index) {
          return ExerciseItem(
            id: favoriteMeals[index].id,
            title: favoriteMeals[index].title,
            imageUrl: favoriteMeals[index].image,
            duration: favoriteMeals[index].duration,
            workoutArea: favoriteMeals[index].workoutArea,
            complexity: favoriteMeals[index].complexity,
          );
        },
        itemCount: favoriteMeals.length,
      );
    }
  }
}
