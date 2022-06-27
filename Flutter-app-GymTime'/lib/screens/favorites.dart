import 'package:flutter/material.dart';
import 'package:workoutapp/Widgets/exercise_item.dart';
import 'package:workoutapp/models/exercise_model.dart';

class FavoritesScreen extends StatelessWidget {
  final List<Exercise> favorite;

  FavoritesScreen(this.favorite);

  @override
  Widget build(BuildContext context) {
    if (favorite.isEmpty) {
      return Scaffold(
        body: Center(
          child: Text('You have no favorites yet!'),
        ),
      );
    } else {
      return ListView.builder(
        itemBuilder: (ctx, index) {
          return ExerciseItem(
            id: favorite[index].id,
            title: favorite[index].title,
            imageUrl: favorite[index].image,
            duration: favorite[index].duration,
            workoutArea: favorite[index].workoutArea,
            complexity: favorite[index].complexity,
          );
        },
        itemCount: favorite.length,
      );
    }
  }
}
