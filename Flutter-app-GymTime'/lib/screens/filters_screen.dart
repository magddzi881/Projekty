import 'package:flutter/material.dart';
import 'package:workoutapp/models/exercise_model.dart';

import '../widgets/main_drawer.dart';

class FiltersScreen extends StatefulWidget {
  static const routeName = '/filters';

  final Function saveFilters;
  final Map<String, bool> currentFilters;

  FiltersScreen(this.currentFilters, this.saveFilters);

  @override
  _FiltersScreenState createState() => _FiltersScreenState();
}

class _FiltersScreenState extends State<FiltersScreen> {
  bool _forBeginners = false;
  bool _easy = false;
  bool _advanced = false;
  bool _hard = false;

  @override
  initState() {
    _forBeginners = widget.currentFilters['forBeginners'] as bool;
    _easy = widget.currentFilters['easy'] as bool;
    _advanced = widget.currentFilters['advanced'] as bool;
    _hard = widget.currentFilters['hard'] as bool;
    super.initState();
  }

  Widget _buildSwitchListTile(
    String title,
    String description,
    bool currentValue,
    var updateValue,
  ) {
    return SwitchListTile(
      title: Text(title),
      value: currentValue,
      subtitle: Text(
        description,
      ),
      onChanged: updateValue,
    );
  }

  List<Exercise> exercises = [];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Your Filters'),
        actions: <Widget>[
          IconButton(
            icon: Icon(Icons.save),
            onPressed: () {
              final selectedFilters = {
                'forBeginners': _forBeginners,
                'easy': _easy,
                'advanced': _advanced,
                'hard': _hard,
              };
              widget.saveFilters(selectedFilters);
            },
          )
        ],
      ),
      drawer: MainDrawer(exercises),
      body: Column(
        children: <Widget>[
          Container(
            padding: EdgeInsets.all(20),
            child: Text(
              'Chose exercises difficulty.',
              style: Theme.of(context).textTheme.headline6,
            ),
          ),
          Expanded(
            child: ListView(
              children: <Widget>[
                _buildSwitchListTile(
                  'For Beginners',
                  'Only exercises for beginners.',
                  _forBeginners,
                  (newValue) {
                    setState(
                      () {
                        _forBeginners = newValue;
                      },
                    );
                  },
                ),
                _buildSwitchListTile(
                  'Easy',
                  'Only easy exercises.',
                  _easy,
                  (newValue) {
                    setState(
                      () {
                        _easy = newValue;
                      },
                    );
                  },
                ),
                _buildSwitchListTile(
                  'Advanced',
                  'Only advanced exercises.',
                  _advanced,
                  (newValue) {
                    setState(
                      () {
                        _advanced = newValue;
                      },
                    );
                  },
                ),
                _buildSwitchListTile(
                  'Hard',
                  'Only hard exercises.',
                  _hard,
                  (newValue) {
                    setState(
                      () {
                        _hard = newValue;
                      },
                    );
                  },
                )
              ],
            ),
          ),
        ],
      ),
    );
  }
}
