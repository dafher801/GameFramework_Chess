#include "Board.h"
#include "UnitSelect.h"

UnitSelect::UnitSelect(Unit * unit)
	: _unit(unit) {}

void UnitSelect::execute()
{
	Command::execute();
	onVisibleButton();
}

void UnitSelect::onVisibleButton()
{
	_unit->onSelected();
	_unit->onVisibleButton();
}
