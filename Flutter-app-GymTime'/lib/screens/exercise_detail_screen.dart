import 'package:flutter/material.dart';

import '../data.dart';

class ExDetailScreen extends StatelessWidget {
  static const routeName = '/detail';

  final Function toggleFavorite;
  final Function isFavorite;

  ExDetailScreen(this.toggleFavorite, this.isFavorite);

  Widget buildSectionTitle(BuildContext context, String text) {
    return Container(
      margin: EdgeInsets.symmetric(vertical: 10),
      child: Text(
        text,
        style: Theme.of(context).textTheme.headline6,
      ),
    );
  }

  Widget buildContainer(
    Widget child,
  ) {
    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        border: Border.all(color: Colors.grey),
        borderRadius: BorderRadius.circular(10),
      ),
      margin: EdgeInsets.all(10),
      padding: EdgeInsets.all(10),
      height: 220,
      width: 400,
      child: child,
    );
  }

  @override
  Widget build(BuildContext context) {
    final exId = ModalRoute.of(context)?.settings.arguments as String;
    final selectedEx = listOfExercises.firstWhere((ex) => ex.id == exId);
    return Scaffold(
      appBar: AppBar(
        title: Text('${selectedEx.title}'),
      ),
      body: SingleChildScrollView(
        child: Column(
          children: <Widget>[
            Container(
              height: 300,
              width: double.infinity,
              child: Image.network(
                selectedEx.image,
                fit: BoxFit.cover,
              ),
            ),
            buildSectionTitle(context, 'Preparation'),
            Card(
                elevation: 7,
                child: Text(
                  selectedEx.preparation.first,
                  textAlign: TextAlign.center,
                  style: TextStyle(fontSize: 15),
                )),
            buildSectionTitle(context, 'Steps'),
            buildContainer(
              ListView.builder(
                itemBuilder: (ctx, index) => Column(
                  children: [
                    ListTile(
                      leading: CircleAvatar(
                        child: Text('# ${(index + 1)}'),
                      ),
                      title: Text(
                        selectedEx.steps[index],
                      ),
                    ),
                    Divider()
                  ],
                ),
                itemCount: selectedEx.steps.length,
              ),
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        child: Icon(
          isFavorite(exId) ? Icons.star : Icons.star_border,
        ),
        onPressed: () => toggleFavorite(exId),
      ),
    );
  }
}
