#pragma once



namespace cereal
{
    /// @name QDateTime serialization
    /// @{
    template <class Archive> inline
    int64_t save_minimal(Archive const&, QDateTime const& aDateTime)
    {
        return aDateTime.toUTC().toSecsSinceEpoch();
    }

    template <class Archive> inline
    void load_minimal(Archive const&, QDateTime& aDateTime, int64_t const& aValue)
    {
        aDateTime = QDateTime::fromSecsSinceEpoch(aValue, Qt::UTC);
    }
    /// @}


    /// @name QColor serialization
    /// @{
    template <class Archive> inline
    std::string save_minimal(Archive const&, QColor const& aColor)
    {
        return aColor.name().toStdString();
    }

    template <class Archive> inline
    void load_minimal(Archive const&, QColor& aColor, std::string const& aValue)
    {
        aColor.setNamedColor(QString::fromStdString(aValue));
    }
    /// @}

}
